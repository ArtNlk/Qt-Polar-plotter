#include "butterflyfunc.h"

#include <cmath>

const std::string ButterflyFunc::name = "Oscar’s Butterfly";

ButterflyFunc::ButterflyFunc()
{

}

float ButterflyFunc::eval(float theta)
{
    return pow(cos(5*theta),2) + sin(3*theta) + 0.3;
}

std::string ButterflyFunc::getName() const
{
    return name;
}
