#ifndef POLARFUNCTION_H
#define POLARFUNCTION_H

#include <string>

class PolarFunction
{
public:
    PolarFunction();
    virtual ~PolarFunction() = default;

public:
    virtual double eval(double theta);
    virtual std::string getName() const;
};

#endif // POLARFUNCTION_H
