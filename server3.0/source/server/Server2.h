#pragma once

#include <iostream>
#include "IEnterIntMatrix.h"
#include "ITransposeAndPrintAnyMatrix.h"

class Server2 : public IEnterIntMatrix, public ITransposeAndPrintAnyMatrix {
private:
    int count;
public:
    HRESULT_ QueryInterface(IID_ Iid, void **ppv);

    ULONG_ addRef();

    ULONG_ Release();

    ~Server2();

    void allocateMemoryForMatrix();

    void clearMemoryForMatrix();

    void enterMatrix(int n, int m);

    void transposeMatrix();

    void printMatrix();
};