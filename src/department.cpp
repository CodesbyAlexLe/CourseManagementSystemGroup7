#include "Department.h"
#include <cstring>
#include <iostream>

Department::Department() : courses(nullptr), totalCourses(0) { name[0] = '\0'; }

Department::Department(const char* newName) : courses(nullptr), totalCourses(0) {
    std::strncpy(name, newName, sizeof(name) - 1); name[sizeof(name) - 1] = '\0';
}

Department::Department(const Department& other) : courses(nullptr), totalCourses(other.totalCourses) {
    std::strncpy(name, other.name, sizeof(name));
    if (totalCourses > 0) {
        courses = new Course[totalCourses];
        for (int i = 0; i < totalCourses; ++i) courses[i] = other.courses[i];
    }
}

Department& Department::operator=(const Department& other) {
    if (this != &other) {
        delete[] courses;
        courses = nullptr;
        totalCourses = other.totalCourses;
        std::strncpy(name, other.name, sizeof(name));
        if (totalCourses > 0) {
            courses = new Course[totalCourses];
            for (int i = 0; i < totalCourses; ++i) courses[i] = other.courses[i];
        }
    }
    return *this;
}

Department::~Department() { delete[] courses; }
const char* Department::getName() const { return name; }
int Department::getTotalCourses() const { return totalCourses; }
Course* Department::getCourse(int index) { return (index >= 0 && index < totalCourses) ? &courses[index] : nullptr; }
const Course* Department::getCourse(int index) const { return (index >= 0 && index < totalCourses) ? &courses[index] : nullptr; }

void Department::addCourse(const Course& course) {
    Course* biggerArray = new Course[totalCourses + 1];
    for (int i = 0; i < totalCourses; ++i) biggerArray[i] = courses[i];
    biggerArray[totalCourses] = course;
    delete[] courses;
    courses = biggerArray;
    ++totalCourses;
}

void Department::listCourses() const {
    if (totalCourses == 0) { std::cout << "No courses in this department.\n"; return; }
    for (int i = 0; i < totalCourses; ++i) {
        std::cout << i + 1 << ". ";
        courses[i].display();
    }
}

