#include <iostream>
#include <iomanip>
#include "Server.h"
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

int components_count = 0;
char buffer[2048];
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
int DelModulePath()
{
    ifstream file_in("manager/wheredll.txt");
    if (!file_in)
    {
        return -1;
    }
    CLSID_ fileCLS_ID;
    string s;
    string filedata = "";

    while (getline(file_in, s))
    {
        istringstream is(s, istringstream::in);
        is >> fileCLS_ID;
        if (fileCLS_ID != clsidServ)
        {
            filedata += s + "\n";
        }
    }
    file_in.close();
    ofstream file_out("D:\\programming\\programming\\server3.0\\source\\manager\\pathToDLL.txt");
    if (!file_out)
    {
        return -1;
    }
    file_out << filedata;
    file_out.close();

    return 0;
}
int SetModulePath()
{
    DelModulePath();
    ofstream file("D:\\programming\\programming\\server3.0\\source\\manager\\manager/pathToDLL.txt", ios_base::app);
    if (!file)
    {
        return -1;
    }
    file << clsidServ << " " << buffer;
    file.close();
    return 0;
}
extern "C" STDAPI __declspec(dllexport) DllRegisterServer()
{
    if (SetModulePath() == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}
extern "C" STDAPI __declspec(dllexport) DllUnregisterServer()
{
    if (DelModulePath() == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}
extern "C" STDAPI __declspec(dllexport) DllCanUnloadNow()
{
    if (components_count == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    GetModuleFileName(hinstDLL, buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}
