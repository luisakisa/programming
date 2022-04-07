#include "ClientWrapper.h"
#include "Functions.h"

#include <iostream>

/**
    IID_
    ИД интерфейсов
    IEnterIntMatrix - 1
    ITransposeAndPrintAnyMatrix - 2
    IClassFactory - 3
*/
CLSID_ Server = 1;
IID_ IClassFactory = 3;
const int  S_OK = 0;

ClientWrapper::ClientWrapper() {
    pF = NULL;
    HRESULT_ res = GetClassObject(Server, IClassFactory, (void**)&pF);
    pF->addRef();
    if (res == S_OK) {
        HRESULT_ res = pF->CreateInstance(1, (void**)&pX);
        pX->addRef();
        HRESULT_ res2 = pX->QueryInterface(2, (void**)&pY);
        pY->addRef();
    }
}

ClientWrapper::~ClientWrapper() {
    pX->Release();
    pY->Release();
    pF->Release();
}

void ClientWrapper::enterMatrix() {

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
    pF->addRef();
    pX = other.pX;
    pX->addRef();
    pY = other.pY;
    pY->addRef();
}
ClientWrapper& ClientWrapper::operator=(const ClientWrapper &other)
{
    if (this == &other)
    {
        return *this;
    }
    if (this->pF)
    {
        this->pF->Release();
        GetClassObject(Server, IClassFactory, (void **)&pF);
        pF->addRef();
    }
    if (this->pX)
    {
        this->pX->Release();
        pF->CreateInstance(1, (void **)&pX);
        pX->addRef();
    }
    if (this->pY)
    {
        this->pY->Release();
        pF->CreateInstance(2, (void **)&pY);
        pY->addRef();
    }
    return *this;
}
