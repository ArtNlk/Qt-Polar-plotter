#include "rosecurvefunc.h"

#include <cmath>

const std::string RoseCurveFunc::name = "Rose curve";

RoseCurveFunc::RoseCurveFunc()
{

}

double RoseCurveFunc::eval(double theta)
{
    return sin(2*theta/5);
}

std::string RoseCurveFunc::getName() const
{
    return name;
}
