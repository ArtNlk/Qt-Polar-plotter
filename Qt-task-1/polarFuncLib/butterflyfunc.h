#ifndef BUTTERFLYFUNC_H
#define BUTTERFLYFUNC_H

#include "polarfunction.h"

class ButterflyFunc : public PolarFunction
{
private:
    static const std::string name;

public:
    ButterflyFunc();

    float eval(float theta) override;
    std::string getName() const override;
};

#endif // BUTTERFLYFUNC_H
