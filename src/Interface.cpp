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
