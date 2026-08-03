#pragma once
#include "Course.h"

class Department {
private:
    char name[100];
    Course* courses;
    int totalCourses;

public:
    Department();
    Department(const char* name);
    Department(const Department& other);
    Department& operator=(const Department& other);
    ~Department();

    const char* getName() const;
    int getTotalCourses() const;
    Course* getCourse(int index);
    const Course* getCourse(int index) const;
    void addCourse(const Course& course);
    void listCourses() const;
};

