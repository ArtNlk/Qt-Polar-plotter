#ifndef ROSECURVEFUNC_H
#define ROSECURVEFUNC_H

#include "polarfunction.h"

class RoseCurveFunc : public PolarFunction
{
private:
    static const std::string name;

public:
    RoseCurveFunc();

    double eval(double theta) override;
    std::string getName() const override;
};

#endif // ROSECURVEFUNC_H
