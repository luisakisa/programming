#pragma once

#include "../server/IClassFactory.h"
#include "../server/IUnknown.h"

extern "C" HRESULT_ __declspec(dllexport) Co_CreateInstance(CLSID_ clsid, IID_ iid, void** ppv);