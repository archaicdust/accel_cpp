#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "handle.h"
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


bool compare_Core_handles(const Handle<Core> cp1, const Handle<Core> cp2)
{
    return compare(*cp1, *cp2);
}
int main()
{
    vector< Handle<Core> > students; // store pointers, not objects
    Handle<Core> record;
    char ch;
    string::size_type maxlen = 0;

    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else 
            record = new Grad;

        record->read(cin); // Handle<T>::->, then virtual call to read
        maxlen = max(maxlen, record->name().size()); // Handle<T>::->
        students.push_back(record);
    }

    // compare must be rewritten to work on const Handle<Core>&
    sort(students.begin(), students.end(), compare_Core_handles);

    for (vector<Core*>::size_type i = 0;
         i != students.size(); ++i) {
        // students[i] is a Handle, which we dereference to call the functions
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
        // no delete statement
    }

    return 0;
}

