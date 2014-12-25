#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;

using std::domain_error;

using std::max;
using std::sort;

using std::setprecision;
using std::streamsize;

using std::string;
using std::list;


int main()
{
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    list<Student_info> fail = extract_fails(students);

    //sort(students.begin(), students.end(), compare);
    students.sort(compare);

    cout << "pass:" << endl;
    for (list<Student_info>::const_iterator iter = students.begin();
         iter != students.end(); ++iter) {
        cout << iter->name
             << string(maxlen + 1 - iter->name.size(), ' ');

        try {
            double student_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << student_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << "fail:" << endl;
    //TODO refactor use extract method
    for (list<Student_info>::const_iterator iter = fail.begin();
         iter != fail.end(); ++iter) {
        cout << iter->name
             << string(maxlen + 1 - iter->name.size(), ' ');

        try {
            double student_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << student_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
