#pragma once
#include <string>
#include <vector>
#include "department.h"

// Shared input validation helpers used by Interface, AdminInterface, and
// StudentInterface. All loop until a valid value is entered, or exit the
// program cleanly if the input stream is closed (EOF).
int getMenuChoice(int minVal, int maxVal, const std::string& prompt);
std::string getNonEmptyString(const std::string& prompt);
double getPositiveDouble(const std::string& prompt);

class Interface {
public:
    Interface(const std::string& dataFile);
    void run();

private:
    std::vector<Department> departments;
    std::string dataFilePath;

    void showInitialMenu();
};
#pragma once
