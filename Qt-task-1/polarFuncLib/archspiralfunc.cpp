#include "archspiralfunc.h"

const std::string ArchSpiralFunc::name = "Archimedes spiral";

ArchSpiralFunc::ArchSpiralFunc()
{

}

float ArchSpiralFunc::eval(float theta)
{
    return 0.1*theta;
}

std::string ArchSpiralFunc::getName() const
{
    return name;
}
