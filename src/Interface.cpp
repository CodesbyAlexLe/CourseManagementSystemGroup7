#include "Interface.h"
#include "AdminInterface.h"
#include "StudentInterface.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

static void exitIfStreamClosed() {
    if (std::cin.eof()) {
        std::cout << "\nInput stream closed. Exiting program.\n";
        std::exit(0);
    }
}

Int getMenuChoice(int minVal, int maxVal, const std::string& prompt) {
    std::string line;
    int choice;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        exitIfStreamClosed();
        std::stringstream ss(line);
        if (ss >> choice && ss.eof() && choice >= minVal && choice <= maxVal) {
            return choice;
        }
        std::cout << "Invalid input, please try again.\n";
    }
}

std::string getNonEmptyString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        exitIfStreamClosed();
        if (!input.empty()) {
            return input;
        }
        std::cout << "Input cannot be empty, please try again.\n";
    }
}

double getPositiveDouble(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        exitIfStreamClosed();
        std::stringstream ss(line);
        if (ss >> value && ss.eof() && value > 0) {
            return value;
        }
        std::cout << "Invalid input, please enter a valid price.\n"
    }
}

Interface::Interface(const std::string& dataFile) : dataFilePath(dataFile) {
    loadDepartmentsFromCSV(dataFilePath, departments);
}

void Interface::run() {
    showInitialMenu();
}

void Interface::showInitialMenu() {
    while (true) {
        std::cout << "\n===== Course Management System =====\n";
        std::cout << "1. Student\n";
        std::cout << "2. Admin\n";
        std::cout << "3. Exit\n";
        int choice = getMenuChoice(1, 3, "Select an option: ");

        if (choice == 1) {
            StudentInterface student(departments);
            student.run();
        }
        else if (choice == 2) {
            AdminInterface admin(departments, dataFilePath);
            admin.run();
        }
        else {
            std::cout << "Exiting program. Goodbye!\n";
            return;
        }
    }
}
