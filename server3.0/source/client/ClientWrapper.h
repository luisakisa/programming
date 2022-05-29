#pragma once

#include <cstddef>

#include "../server/IClassFactory.h"
#include "../server/IEnterIntMatrix.h"
#include "../server/ITransposeAndPrintAnyMatrix.h"

class ClientWrapper
{
private:
    IClassFactory_* pF = NULL;
    IEnterIntMatrix* pX = NULL;
    ITransposeAndPrintAnyMatrix* pY = NULL;

public:
    ClientWrapper();
    ClientWrapper(const ClientWrapper &other);
    ~ClientWrapper();
    void enterMatrix();
    void transposeAndPrintMatrix();
    ClientWrapper& operator= (const ClientWrapper& other);
};