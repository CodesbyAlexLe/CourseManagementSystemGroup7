#include "StudentInterface.h"
#include "Interface.h"
#include <iostream>

StudentInterface::StudentInterface(std::vector<Department>& depts) : departments(depts) {}

void StudentInterface::run() {
    while (true) {
        std::cout << "\n----- Student Main Menu -----\n";
        std::cout << "1. Show Cart\n";
        std::cout << "2. Browse Departments\n";
        std::cout << "3. Exit\n";
        int choice = getMenuChoice(1, 3, "Select an option: ");

        switch (choice) {
        case 1: showCart(); break;
        case 2: browseDepartments(); break;
        case 3: return; // back to Initial Menu
        }
    }
}

void StudentInterface::showCart() {
    std::cout << "\n----- Your Cart -----\n";
    cart.display();

    std::cout << "1. Checkout\n";
    std::cout << "2. Return to Main Menu\n";
    int choice = getMenuChoice(1, 2, "Select an option: ");

    if (choice == 1) {
        checkout();
    }
    // choice == 2 falls through and returns to Main Menu
}

void StudentInterface::checkout() {
    if (cart.isEmpty()) {
        std::cout << "Your cart is empty\n";
    }
    else {
        std::cout << "Thank you for your purchase\n";
        cart.clear();
    }
}

void StudentInterface::browseDepartments() {
    if (departments.empty()) {
        std::cout << "No departments available.\n";
        return;
    }

    while (true) {
        std::cout << "\n----- Departments -----\n";
        for (size_t i = 0; i < departments.size(); i++) {
            std::cout << (i + 1) << ". " << departments[i].name << "\n";
        }
        std::cout << (departments.size() + 1) << ". Go Back to Main Menu\n";

        int choice = getMenuChoice(1, (int)departments.size() + 1, "Select an option: ");
        if (choice == (int)departments.size() + 1) {
            return; // back to Student Main Menu
        }

        listCoursesInDepartment(departments[choice - 1]);
    }
}

void StudentInterface::listCoursesInDepartment(Department& dept) {
    while (true) {
        std::cout << "\n----- " << dept.name << " Courses -----\n";
        if (dept.courses.empty()) {
            std::cout << "No courses available in this department.\n";
        }
        else {
            for (size_t i = 0; i < dept.courses.size(); i++) {
                std::cout << (i + 1) << ". ";
                dept.courses[i].display();
                std::cout << "\n";
            }
        }

        std::cout << "1. Add to Cart\n";
        std::cout << "2. Go Back to Departments Menu\n";
        int choice = getMenuChoice(1, 2, "Select an option: ");

        if (choice == 1) {
            addCourseToCart(dept);
        }
        else {
            return; // back to Browse Departments
        }
    }
}

void StudentInterface::addCourseToCart(Department& dept) {
    if (dept.courses.empty()) {
        std::cout << "No courses available to add.\n";
        return;
    }

    std::string number = getNonEmptyString("Enter the course number to add: ");
    Course* course = dept.findCourse(number);

    if (!course) {
        std::cout << "Course number not found, please try again.\n";
        return;
    }

    cart.addCourse(*course);
    std::cout << "Course added to cart\n";
}
