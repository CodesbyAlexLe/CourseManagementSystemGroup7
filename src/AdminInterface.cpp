#include "AdminInterface.h"
#include "Interface.h"
#include <iostream>

AdminInterface::AdminInterface(std::vector<Department>& depts, const std::string% filePath)
    : departments(depts), dataFilePath(filePath) {
}

void AdminInterface::run() {
    while (true) {
        std::cout << "\n----- Admin Main Menu -----\n";
        std::cout << "1. List Departments\n";
        std::cout << "2. Add Departments\n";
        std::cout << "3. Add Course to Department\n";
        std::cout << "4. Save Changes in CSV\n";
        std::cout << "5. Exit\n";
        int choice = getMenuChoice(1, 5, "Select an option: ");

        switch (choice) {
        case 1: listDepartments(); break;
        case 2: addDepartment(); break;
        case 3: addCourseToDepartment(); break;
        case 4: saveChanges(); break;
        case 5: return; // back to Initial Menu
        }
    }
}

void AdminInterface::listDepartments() {
    std::cout << "\n----- Departments -----\n";
    if (departments.empty()) {
        std::cout << "No departments available.\n";
        return;
    }
    for (size_t i = 0; i < departments.size(); i++) {
        std::cout << (i + 1) << ". " << departments[i].name << "\n";
    }
}

void AdminInterface::addDepartment() {
    std::string name = getNonEmptyString("Department name: ");
    departments.push_back(Department(name));
    std::cout <<"Department added successfully\n;
}

void AdminInterface::addCourseToDepartment() {
    if (departments.empty()) {
        std::cout << "No departments available. Please add a department first.\n";
        return;
    }
