#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;


Student_info::Student_info(): midterm(0), finalterm(0) {}
Student_info::Student_info(istream& is) { read(is); }


istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> finalterm;
    read_hw(in, homework);
    return in;
}


double Student_info::grade() const
{
    return ::grade(midterm, finalterm, homework);
}


bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
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


