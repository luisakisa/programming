#include "Functions.h"

#include "IUnknown.h"
#include "IClassFactory.h"

/*
    1 аргумент - ид сервера (1 или 2)
    2 аргумент - ид фабрики (3)
    3 аргумент - указатель на фабрику, которая конструируется в этой функции
*/
HRESULT_ DLL_GetClassObject(CLSID_ S, IID_ I, void** pF) {
    if (I == ICLASS_FACTORY_IID) {
        *pF = new Factory(S);
        return 0;
    } else {return 1;}
    
}