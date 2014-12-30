#include <iostream>
#include <algorithm>
#include "grad.h"

using std::istream;
using std::min;


// implicitly use Core::Core() to initialize the base part
Grad::Grad(): thesis(0) {}

// implicitly use Core::Core() to initialize the base part
Grad::Grad(istream& is) { read(is); }

istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}


double Grad::grade() const
{
    return min(Core::grade(), thesis);
}
