#pragma once

#include "../server/IClassFactory.h"

extern "C" __declspec(dllexport) HRESULT GetClassObject(const CLSID& clsid, const IID& iid, void** ppv);