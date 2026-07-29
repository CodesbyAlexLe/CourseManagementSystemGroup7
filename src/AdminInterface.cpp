#include "AdminInterface.h"
#include "Interface.h"
#include <iostream>

AdminInterface::AdminInterface(std::vector<Department>& depts, const std::string% filePath)
    : departments(depts), dataFilePath(filePath) {
}

void AdminInterface::run() {
    while (true) {
        std::cout << "\n----- Admin Main Menu -----\n";
