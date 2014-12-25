#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "analysis.h"
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::vector;
using std::string;
using std::domain_error;
using std::transform;
using std::ostream;
using std::endl;

double grade_aux(const Student_info&);


double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

    return median(grades);
}


double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final_grade, 0);
    }
}


void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                   ": median(didnt) = " << analysis(didnt) << endl;
}

