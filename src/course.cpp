#include "Course.h"
#include <cstring>
#include <iomanip>
#include <iostream>

Course::Course() : price(0.0) {
    number[0] = '\0'; name[0] = '\0'; schedule[0] = '\0';
}

Course::Course(const char* newNumber, const char* newName,
               const char* newSchedule, double newPrice) : price(newPrice) {
    std::strncpy(number, newNumber, sizeof(number) - 1); number[sizeof(number) - 1] = '\0';
    std::strncpy(name, newName, sizeof(name) - 1); name[sizeof(name) - 1] = '\0';
    std::strncpy(schedule, newSchedule, sizeof(schedule) - 1); schedule[sizeof(schedule) - 1] = '\0';
}

const char* Course::getNumber() const { return number; }
const char* Course::getName() const { return name; }
const char* Course::getSchedule() const { return schedule; }
double Course::getPrice() const { return price; }

void Course::display() const {
    std::cout << number << " | " << name << " | " << schedule << " | $"
              << std::fixed << std::setprecision(2) << price << '\n';
}
