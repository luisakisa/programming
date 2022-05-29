#pragma once
#include "IUnknown.h"

CLSID_ SERVER = 1;
IID_ ICLASS_FACTORY = 3;
const int  S_OK_ = 0;

HRESULT_ GetClassObject(CLSID_ S, IID_ I,void** pF);