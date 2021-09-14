#include "polarfunction.h"

PolarFunction::PolarFunction()
{

}

double PolarFunction::eval(double theta)
{
    return 1;
}

std::string PolarFunction::getName() const
{
    return std::string("Bad function");
}
