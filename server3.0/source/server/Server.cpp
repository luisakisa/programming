#include <iostream>
#include <iomanip>
#include "Server.h"

using namespace std;
 
Server::Server{
    FunctionType f;
    HINSTANCE h;
    h = LoadLibrary("C++/Server.dll");
    if (!h)
    {
        std::cout << "no dll" << std::endl;
    }

    f = (FunctionType)GetProcAddress(h, "GetClassObject");
    if (!f)
    {
        std::cout << "no dll func" << std::endl;
    }
    
    f(clsidServ, iid_IClassFactory, (void **)&fact);

    fact->CreateInstance(iid_IEnter, (void **)&enterMatr);

    enterMatr->QueryInterface(iid_ITandP, (void **)&TandP);

    system("pause");
}

Server::~Server()
{
    clearMemoryForMatrix();
    cout<<"Server is deleted"<<endl;
}
HRESULT_ Server::QueryInterface(IID_ Iid, void **ppv){
    if(Iid == 0){
        *ppv = (IUnknown*)((IEnterIntMatrix*)this);
        return 0;
    }
    else if(Iid == 1){
        *ppv = (IEnterIntMatrix*)this;
        return 0;
    }
    else if(Iid == 2){
        *ppv = (ITransposeAndPrintAnyMatrix*)this;
        return 0;
    }
    else{
        *ppv= NULL;
        return 1;
    }
}
ULONG_ Server::addRef(){
    count++;
    cout<<"Pointer++"<<endl;
}; 
ULONG_ Server::Release(){
    count--;
    cout<<"Pointer--";
    if (count==0){
        cout<<"Pointers are deleted"<<endl;
        delete this;
    }
}

void Server::allocateMemoryForMatrix() {
    matr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matr[i] = new int[m];
    }
}

void Server::clearMemoryForMatrix() {
    for (int i = 0; i < n; i++)
    {
        delete[] matr[i];
    }
    delete[] matr;
}

void Server::enterMatrix(int n, int m) {
    this->n = n;
    this->m = m;
    allocateMemoryForMatrix();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Enter element with index:" << i << " " << j << std::endl;
            std::cin >> matr[i][j];
        }
    }
}

void Server::transposeMatrix() {
    int buff;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            buff = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = buff;
        }
    }
}

void Server::printMatrix() {
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << std::setw(15) << matr[i][j];
        std::cout << std::endl;
    }
};
