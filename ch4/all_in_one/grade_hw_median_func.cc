#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <iostream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::domain_error;
using std::sort;


double grade(double midterm, double final_grade, double homework)
{
    return 0.2 * midterm + 0.4 * final_grade + 0.4 * homework;
}


double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;
    return size %2 == 0 ? (vec[mid] + vec[mid-1]) /2
                        : vec[mid];
}


double grade(double midterm, double final_grade, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final_grade, median(hw));
}

using std::istream;
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();

        double x;
        while (in >> x)
            hw.push_back(x);
    }
    return in;
}


int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final grades: :";
    double midterm, final_grade;
    cin >> midterm >> final_grade;

    cout << "Enter your homework grades, "
        "followed by end-of-file: ";

    vector<double> homework;
    read_hw(cin, homework);

    using std::streamsize;
    using std::setprecision;
    try {
        double student_grade = grade(midterm, final_grade, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << student_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return 1;
    }
    return 0;
}

