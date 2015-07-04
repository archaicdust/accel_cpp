#include <vector>
#include <iostream>

#include "median.h"

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<double> grade(3);
    grade[0] = 3;
    grade[1] = 10;
    grade[2] = 8.8;

    cout << "float: ";
    cout << median(grade) << endl;

    vector<int> int_grade(4);
    // 11 22 33 55
    int_grade[0] = 22;
    int_grade[1] = 11;
    int_grade[2] = 33;
    int_grade[3] = 55;

    cout << "int: ";
    cout << median(int_grade) << endl;
}
