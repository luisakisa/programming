#pragma once

#include "Variables.h"

class ITransposeAndPrintAnyMatrix: public IUnknown
{
public:
    virtual void __stdcall transposeMatrix() = 0;
    virtual void __stdcall printMatrix() = 0;
    virtual ~ITransposeAndPrintAnyMatrix() {};
};
