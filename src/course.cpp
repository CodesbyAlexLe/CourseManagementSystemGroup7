#include "course.h"
#include <iostream>
#include <iomanip>

Course::Course() : courseNumber(""), courseName(""), schedule(""), price(0.0) {}

Course::Course(const std::string& number, const std::string& name, const std::string& sched, double p)
    : courseNumber(number), courseName(name), schedule(sched), price(p) {
}

void Course::display() const {
    std::cout << courseName << " (" << courseNumber << ")"
        << " | " << schedule
        << " | $" << std::fixed << std::setprecision(2) << price;
}
