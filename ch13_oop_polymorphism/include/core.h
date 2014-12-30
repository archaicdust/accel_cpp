#ifndef GUARD_core_h
#define GUARD_core_h

#include <iostream>
#include <string>
#include <vector>

class Core {
public:
    Core();
    Core(std::istream&);

    virtual ~Core() { }

    std::string name() const;

    virtual std::istream& read(std::istream&);
    virtual double grade() const;

protected:
    std::istream& read_common(std::istream&);
    double midterm, finalterm;
    std::vector<double> homework;

private:
    std::string n;
};

std::istream& read_hw(std::istream&, std::vector<double>&);

bool compare(const Core&, const Core&);

#endif

