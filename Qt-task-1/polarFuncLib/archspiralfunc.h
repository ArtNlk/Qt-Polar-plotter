#ifndef ARCHSPIRALFUNC_H
#define ARCHSPIRALFUNC_H

#include "polarfunction.h"

#include <string>

class ArchSpiralFunc : public PolarFunction
{
private:
    static const std::string name;
public:
    ArchSpiralFunc();

    float eval(float theta) override;
    std::string getName() const override;
};

#endif // ARCHSPIRALFUNC_H
