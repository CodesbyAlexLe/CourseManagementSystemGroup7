#pragma once
#include <string>
#include <vector>
#include "course.h"

class Department {
public:
    std::string name;
    std::vector<Course> courses;

    Department();
    Department(const std::string& n);

    // Returns pointer to course with matching number, or nullptr if not found
    Course* findCourse(const std::string& courseNumber);
};

// Returns pointer to department with matching name, or nullptr if not found
Department* findDepartment(std::vector<Department>& departments, const std::string& name);

// CSV format: DepartmentName,CourseNumber,CourseName,Schedule,Price
bool loadDepartmentsFromCSV(const std::string& filename, std::vector<Department>& departments);
bool saveDepartmentsToCSV(const std::string& filename, const std::vector<Department>& departments);
#pragma once
