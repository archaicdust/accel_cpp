#include <iostream>
#include <vector>

#include "core.h"
#include "grade.h"

using std::string;
using std::istream;
using std::vector;


Core::Core():midterm(0), finalterm(0) { }

Core::Core(istream& is) { read(is); }

string Core::name() const { return n; }


double Core::grade() const
{
    return ::grade(midterm, finalterm, homework);
}


istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> finalterm;
    return in;
}


istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}


istream& read_hw(istream& in , vector<double>& hw)
{
    if (in) {
        hw.clear();

        double x;
        while (in >>x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}

