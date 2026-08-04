#pragma once
#include <string>
#include <vector>
#include "department.h"

class AdminInterface {
public:
    AdminInterface(std::vector<Department>& departments, const std::string& dataFilePath);
    void run();

private:
    std::vector<Department>& departments;
    std::string dataFilePath;

    void listDepartments();
    void addDepartment();
    void addCourseToDepartment();
    void saveChanges();
};

