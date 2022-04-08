#pragma once
#include "IUnknown.h"
class ITransposeAndPrintAnyMatrix: public IUnknown
{
public:
    virtual void transposeMatrix() = 0;
    virtual void printMatrix() = 0;
};
