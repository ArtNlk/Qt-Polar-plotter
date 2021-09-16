#ifndef HEADFUNC_H
#define HEADFUNC_H

#include "polarfunction.h"

class HeadFunc : public PolarFunction
{
private:
    static const std::string name;

public:
    HeadFunc();

    double eval(double theta) override;
    std::string getName() const override;
};

#endif // HEADFUNC_H
