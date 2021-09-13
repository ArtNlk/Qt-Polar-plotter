#include "polarfunction.h"

PolarFunction::PolarFunction()
{

}

float PolarFunction::eval(float theta)
{
    return 1;
}

std::string PolarFunction::getName() const
{
    return std::string("Bad function");
}
