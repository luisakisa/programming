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

    void allocateMemoryForMatrix();

    void clearMemoryForMatrix();

    void enterMatrix(int n, int m);

    void transposeMatrix();

    void printMatrix();
};
