#pragma once

#include <cstddef>

#include "../server/IEnterIntMatrix.h"
#include "../server/ITransposeAndPrintAnyMatrix.h"

typedef HRESULT __stdcall (*GetClassObjectType) (const CLSID& clsid, const IID& iid, void** ppv);

enum RunType {
    ManagerEmulator,
    ComLibraryFactory,
    ComLibraryInstance
};

class ClientWrapper
{
private:
    IEnterIntMatrix* pX = NULL;
    ITransposeAndPrintAnyMatrix* pY = NULL;
    IClassFactory* pF = NULL;
    GetClassObjectType getClassObjectTypeFunction;

    ClientWrapper() = delete;
    CLSID clsidServer;
public:
    ClientWrapper(RunType runType, bool getClsidFromRegistr);
    ClientWrapper(const ClientWrapper &other);
    
    ~ClientWrapper();
    void enterMatrix();
    void transposeAndPrintMatrix();
    void dispatch();
    ClientWrapper& operator= (const ClientWrapper& other);
};