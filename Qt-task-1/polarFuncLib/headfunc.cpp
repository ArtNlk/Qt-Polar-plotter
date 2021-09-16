#include "headfunc.h"

#include <cmath>

const std::string HeadFunc::name = "Head curve";

HeadFunc::HeadFunc()
{

}

double HeadFunc::eval(double theta)
{
    return sin(pow(2,theta)) - 1.7;
}

std::string HeadFunc::getName() const
{
    return name;
}
