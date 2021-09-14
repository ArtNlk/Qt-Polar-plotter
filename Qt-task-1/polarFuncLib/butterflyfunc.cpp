#include "butterflyfunc.h"

#include <cmath>

const std::string ButterflyFunc::name = "Oscar’s Butterfly";

ButterflyFunc::ButterflyFunc()
{

}

double ButterflyFunc::eval(double theta)
{
    return pow(cos(5*theta),2) + sin(3*theta) + 0.3;
}

std::string ButterflyFunc::getName() const
{
    return name;
}
