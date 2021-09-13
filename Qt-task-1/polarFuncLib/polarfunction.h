#ifndef POLARFUNCTION_H
#define POLARFUNCTION_H

#include <string>

class PolarFunction
{
public:
    PolarFunction();
    ~PolarFunction();

public:
    virtual float eval(float theta);
    virtual std::string getName() const;
};

#endif // POLARFUNCTION_H
