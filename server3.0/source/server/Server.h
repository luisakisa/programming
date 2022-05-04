#pragma once
#include <iostream>
#include "IEnterIntMatrix.h"
#include "ITransposeAndPrintAnyMatrix.h"

class Server: public IEnterIntMatrix, public ITransposeAndPrintAnyMatrix
{
private:
    int n, m;
    int **matr;
    int count = 0;
public:
    ~Server();
    HRESULT_ QueryInterface(IID_ Iid, void **ppv);
    ULONG_ addRef();
    ULONG_ Release();

    virtual void allocateMemoryForMatrix();

    virtual void clearMemoryForMatrix();

    virtual void enterMatrix(int n, int m);

    virtual void transposeMatrix();

    virtual void printMatrix();
};
