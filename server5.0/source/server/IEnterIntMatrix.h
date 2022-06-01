#pragma once

#include "Variables.h"

class IEnterIntMatrix: public IUnknown
{
public:
    virtual void __stdcall allocateMemoryForMatrix() = 0;
    virtual void __stdcall clearMemoryForMatrix() = 0;
    virtual void __stdcall enterMatrix(int n, int m) = 0;
    virtual ~IEnterIntMatrix() {};
};
