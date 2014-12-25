#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <iostream>

#include "Student_info.h"


double median_analysis(const std::vector<Student_info>&);

void write_analysis(std::ostream& out, const std::string& name,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);
#endif

