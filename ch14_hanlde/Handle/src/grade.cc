#include <stdexcept>
#include <vector>

#include "grade.h"
#include "median.h"

using std::domain_error;
using std::vector;


double grade(double midterm, double finalterm, double homework)
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}


double grade(double midterm, double finalterm, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, finalterm, median(hw));
}


