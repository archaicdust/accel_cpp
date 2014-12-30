#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "core.h"
#include "grade.h"
#include "grad.h"

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


bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
    return compare(*cp1, *cp2);
}

int main()
{
    vector<Core*> students; // store pointers, not objects
    Core* record;
    char ch;
    string::size_type maxlen = 0;

    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else 
            record = new Grad;

        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_ptrs);

    for (vector<Core*>::size_type i = 0;
         i != students.size(); ++i) {
        cout << students[i]->name()
             << string(maxlen + 1 - students[i]->name().size(), ' ');

        try {
            double student_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << student_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
        delete students[i]; // free the object allocated when  reading
    }

    return 0;
}

