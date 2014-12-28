#ifndef GUARD_Student_h
#define GUARD_Student_h

#include <iostream>
#include <string>
#include <vector>


class Student_info {
    std::string n;
    double midterm, finalterm;
    std::vector<double> homework;

public:
    Student_info();
    Student_info(std::istream&);
    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
};


bool compare(const Student_info&, const Student_info&);

std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
