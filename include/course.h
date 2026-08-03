#pragma once
#include <string>

class Course {
public:
    std::string courseNumber;
    std::string courseName;
    std::string schedule;
    double price;

    Course();
    Course(const std::string& number, const std::string& name, const std::string& sched, double p);

    // Prints "Name (Number) | Schedule | $Price"
    void display() const;
};

