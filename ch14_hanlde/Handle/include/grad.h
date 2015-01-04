#ifndef GUARD_grad_h
#define GUARD_grad_h

#include "core.h"


class Grad: public Core {
public:
    Grad();
    Grad(std::istream&);
    virtual double grade() const;
    virtual std::istream& read(std::istream&);

protected:
    virtual Grad* clone() const { return new Grad(*this); }

private:
    double thesis;
};


#endif
