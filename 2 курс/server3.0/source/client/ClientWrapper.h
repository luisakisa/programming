#pragma once

#include <cstddef>

#include "../server/IEnterIntMatrix.h"
#include "../server/ITransposeAndPrintAnyMatrix.h"

typedef HRESULT_ (*CreateInstanceFunction)(CLSID_, IID_, void **);

class ClientWrapper
{
private:
    IEnterIntMatrix* pX = NULL;
    ITransposeAndPrintAnyMatrix* pY = NULL;
    CreateInstanceFunction coCreateInstanceFunction;

public:
    ClientWrapper();
    ClientWrapper(const ClientWrapper &other);
    ~ClientWrapper();
    void enterMatrix();
    void transposeAndPrintMatrix();
    ClientWrapper& operator= (const ClientWrapper& other);
};