#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"
#include "analysis.h"

using std::cin;
using std::cout;
using std::endl;

using std::domain_error;

using std::max;
using std::sort;

using std::setprecision;
using std::streamsize;

using std::string;
using std::vector;


int main()
{
    vector<Student_info> did, didnt;
    Student_info student;

    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }


    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);

    return 0;
}
