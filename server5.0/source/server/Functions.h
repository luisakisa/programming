#pragma once

#include "windows.h"

HRESULT __stdcall GetClassObject(const CLSID& clsid, const IID& iid, void** ppv);