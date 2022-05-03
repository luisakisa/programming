#pragma once
#include "IUnknown.h"
CLSID_ Server = 1;
IID_ IClassFactory = 3;
const int  S_OK = 0;
HRESULT_ GetClassObject(CLSID_ S, IID_ I,void** pF);