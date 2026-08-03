#include "Cart.h"
#include <cstring>
#include <iomanip>
#include <iostream>

Cart::Cart() : courses(nullptr), schedules(nullptr), totalCourses(0), totalCost(0.0) {}
Cart::~Cart() { delete[] courses; delete[] schedules; }
bool Cart::isEmpty() const { return totalCourses == 0; }

void Cart::calculateTotal() {
    totalCost = 0.0;
    for (int i = 0; i < totalCourses; ++i) totalCost += courses[i].getPrice();
}

void Cart::addCourse(const Course& course) {
    Course* biggerArray = new Course[totalCourses + 1];
    char (*biggerSchedules)[10] = new char[totalCourses + 1][10];
    for (int i = 0; i < totalCourses; ++i) biggerArray[i] = courses[i];
    for (int i = 0; i < totalCourses; ++i) std::strcpy(biggerSchedules[i], schedules[i]);
    biggerArray[totalCourses] = course;
    std::strcpy(biggerSchedules[totalCourses], course.getSchedule());
    delete[] courses;
    delete[] schedules;
    courses = biggerArray;
    schedules = biggerSchedules;
    ++totalCourses;
    calculateTotal();
}

void Cart::clear() { delete[] courses; delete[] schedules; courses = nullptr; schedules = nullptr; totalCourses = 0; totalCost = 0.0; }

void Cart::display() const {
    if (isEmpty()) { std::cout << "No courses in the cart\n"; return; }
    std::cout << "\n----- Cart -----\n";
    for (int i = 0; i < totalCourses; ++i) { std::cout << i + 1 << ". "; courses[i].display(); }
    std::cout << "Subtotal: $" << std::fixed << std::setprecision(2) << totalCost << '\n';
    std::cout << "Total with 13% tax: $" << totalCost * 1.13 << '\n';
}

