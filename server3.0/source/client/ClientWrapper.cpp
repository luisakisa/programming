#include "ClientWrapper.h"
#include "../server/Functions.h"

#include "windows.h"

#include <iostream>

/**
    IID_
    ИД интерфейсов
    IEnterIntMatrix - 1
    ITransposeAndPrintAnyMatrix - 2
    IClassFactory - 3
*/

ClientWrapper::ClientWrapper() {
    HINSTANCE h = LoadLibrary("build/Manager.dll");
    if (!h)
    {
        std::cout << "dll not found" << std::endl;
    }

    coCreateInstanceFunction = (CreateInstanceFunction)GetProcAddress(h, "Co_CreateInstance");
    if (!coCreateInstanceFunction)
    {
        std::cout << "Co_CreateInstance on dll" << std::endl;
    }
    coCreateInstanceFunction(SERVER1_CLSID, ENTER_MATRIX_IID, (void **)&pX);

    pX->QueryInterface(TRANSPOSE_MATRIX_IID, (void **)&pY);
}

ClientWrapper::~ClientWrapper() {
    pX->Release();
    pY->Release();
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
    pX = other.pX;
    pX->addRef();
    pY = other.pY;
    pY->addRef();
}
ClientWrapper& ClientWrapper::operator=(const ClientWrapper &other) {
    if (this == &other)
    {
        return *this;
    }
    if (coCreateInstanceFunction) {
        if (this->pX) {
            this->pX->Release();
            coCreateInstanceFunction(SERVER1_CLSID, ICLASS_FACTORY_IID, (void **)&pX);
            pX->addRef();
        }
        if (this->pY) {
            this->pY->Release();
            coCreateInstanceFunction(SERVER2_CLSID, ICLASS_FACTORY_IID, (void **)&pY);
            pY->addRef();
        }
    }
    return *this;
}
