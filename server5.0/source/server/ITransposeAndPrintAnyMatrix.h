#pragma once
#include "IUnknown.h"
class ITransposeAndPrintAnyMatrix: public IUnknown_
{
public:
    virtual void transposeMatrix() = 0;
    virtual void printMatrix() = 0;
    virtual ~ITransposeAndPrintAnyMatrix() {};
};
