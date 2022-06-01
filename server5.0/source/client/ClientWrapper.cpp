#include "ClientWrapper.h"
#include "../server/Functions.h"

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

// //{91A42CAA-2577-4E80-934E-07DE64502FD6}
// const CLSID CLSID_Server1 = {0x91A42CAA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

// //{91A42CAB-2577-4E80-934E-07DE64502FD6}
// const CLSID CLSID_Server2 = {0x91A42CAB,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

/**
    IID_
    ИД интерфейсов
    IEnterIntMatrix - 1
    ITransposeAndPrintAnyMatrix - 2
    IClassFactory - 3
*/

ClientWrapper::ClientWrapper(RunType runType, bool getClsidFromRegistr) {
    cout << "ClientWrapper::constructinrg on run type: " << runType << endl
        << "get CLSID from registr trought ProgID: " << (getClsidFromRegistr ? "true" : "false") << endl;

    cout << "ClientWrapper start constructor" << endl;

    try
    {

        //Initializing COM library (Begin)
        CoInitialize(NULL);
        //Initializing COM library (End)

        if (getClsidFromRegistr)
        {
            const wchar_t* progID = L"Kisaluisa.Application";
            //mbstowcs
            //wcstombs
            HRESULT resCLSID_ProgID = CLSIDFromProgID(progID, &clsidServer);
            if (!(SUCCEEDED(resCLSID_ProgID)))
            {
                clsidServer = CLSID_Server1;
                cout << "No CLSID form ProgID" << endl;
            }
            else
            {
                cout << "CLSID form ProgID OK!" << endl;
                if(clsidServer == CLSID_Server1)
                {
                    cout << "got server1 CLSID from registry" << endl;
                }
                else if(clsidServer == CLSID_Server2)
                {
                    cout << "got server2 CLSID from registry" << endl;
                }
            }
        }
        else
        {
            clsidServer = CLSID_Server1;
        }

        if (runType == RunType::ManagerEmulator || runType == RunType::ComLibraryFactory) 
        {
            HRESULT factoryCreationResult;

            if (runType == RunType::ManagerEmulator)
            {
                HINSTANCE h = LoadLibrary("./build/Manager.dll");
                if (!h)
                {
                    std::cout << "Manager.dll not found" << std::endl;
                }

                getClassObjectTypeFunction = (GetClassObjectType) GetProcAddress(h,"GetClassObject");
                if (!getClassObjectTypeFunction)
                {
                    throw "No manager method";
                }

                
                factoryCreationResult = getClassObjectTypeFunction(clsidServer, IID_IClassFactory, (void**)&pF);
            }
            else
            {
                factoryCreationResult = CoGetClassObject(clsidServer,
                    CLSCTX_INPROC_SERVER,
                    NULL,
                    IID_IClassFactory,
                    (void**)&pF
                );
            }

            if (!(SUCCEEDED(factoryCreationResult)))
            {
                throw "Factory getting error: " + std::to_string(factoryCreationResult);
            }
        }

        HRESULT instanceCreationResult;

        if (runType == RunType::ManagerEmulator || runType == RunType::ComLibraryFactory)
        {
            instanceCreationResult = pF->CreateInstance(NULL, IID_IEnterIntMatrix, (void**)&pX);
        }
        else
        {
            instanceCreationResult = CoCreateInstance(clsidServer, NULL, CLSCTX_INPROC_SERVER, IID_IEnterIntMatrix, (void**)&pX);
        }

        if (!(SUCCEEDED(instanceCreationResult)))
        {
            throw "Instance creation error " + std::to_string(instanceCreationResult);
        }



        HRESULT resQuery = pX->QueryInterface(IID_ITransposeMatrix, (void**)&pY);
        if (!(SUCCEEDED(resQuery)))
        {
            throw "Query transpose matrix interface error";
        }
    }
    catch(const std::exception& ex)
    {
        std::cout << "ClientWrapper::Exception: " << ex.what() << endl;
    }
    catch (const std::string& ex)
    {
        std::cout << "ClientWrapper::Exception: " << ex << endl;
    }
    catch (const char* ex)
    {
        std::cout << "ClientWrapper::Exception: " << ex << endl;
    }
    catch (...)
    {
        std::cout << "ClientWrapper::Exception: Unknown\n" << endl;
    }
}

ClientWrapper::~ClientWrapper() {
    pF->Release();
    pX->Release();
    pY->Release();

    //Uninitializing COM library (Begin)
    CoUninitialize();
    //Uninitializing COM library (End)

    cout << "Client wrapper destructed" << endl;
}

void ClientWrapper::enterMatrix() {

    std::cout << "enter matrix dimentions (N x M):";
    int n;
    int m;
    std::cin >> n;
    std::cin >> m;

    pX->enterMatrix(n, m);
}

void ClientWrapper::transposeAndPrintMatrix() {
    pY->printMatrix();
    pY->transposeMatrix();
    pY->printMatrix();
}

ClientWrapper::ClientWrapper(const ClientWrapper &other)
{
    pF = other.pF;
    pF->AddRef();
    pX = other.pX;
    pX->AddRef();
    pY = other.pY;
    pY->AddRef();
}

ClientWrapper& ClientWrapper::operator=(const ClientWrapper &other) {
    if (this == &other)
    {
        return *this;
    }
    
    if (this->pX) {
        this->pX->Release();
        pF->CreateInstance(NULL, IID_IEnterIntMatrix, (void**)&pX);
        pX->AddRef();
    }
    if (this->pY) {
        this->pY->Release();
        pF->CreateInstance(NULL, IID_ITransposeMatrix, (void**)&pY);
        pY->AddRef();
    }
    
    return *this;
}

void ClientWrapper::dispatch()
{
    try
    {
        IDispatch *pDisp = NULL;
        HRESULT resultQueryDispatch = pX->QueryInterface(IID_IDispatch, (void **)&pDisp);
        if (!(SUCCEEDED(resultQueryDispatch)))
        {
            throw "Query dispatch interface error";
        }

        DISPID dispid;

        int namesCount = 1;
        OLECHAR **names = new OLECHAR *[namesCount];
        OLECHAR *name = const_cast<OLECHAR *>(L"printMatrix");
        names[0] = name;
        HRESULT resID_Name = pDisp->GetIDsOfNames(
            IID_NULL,
            names,
            namesCount,
            GetUserDefaultLCID(),
            &dispid);
        if (!(SUCCEEDED(resID_Name)))
        {
            cout << "ClientWrapper::dispatch method not found" << endl;
        }
        else
        {
            DISPPARAMS dispparamsNoArgs = {
                NULL,
                NULL,
                0,
                0,
            };

            HRESULT resInvoke = pDisp->Invoke(
                dispid, // DISPID
                IID_NULL,
                GetUserDefaultLCID(),
                DISPATCH_METHOD,
                &dispparamsNoArgs,
                NULL,
                NULL,
                NULL);

            if (!(SUCCEEDED(resInvoke)))
            {
                cout << "ClientWrapper::dispatch invoke method error" << endl;
            }
        }

        pDisp->Release();
    }
    catch (const char* ex)
    {
        cout << "ClientWrapper::dispatch exception: " << ex << endl;
    }
    catch (...)
    {
        cout << "ClientWrapper::dispatch exception: Unknown" << endl;
    }
}