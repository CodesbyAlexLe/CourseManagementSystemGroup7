#include "AdminInterface.h"
#include "Data.h"
#include "StudentInterface.h"
#include <iostream>
//global data
Department* StoreDepartments = nullptr;
int TotalDepartments = 0;
const char* csvFile = "course_data.csv";

int main() {
  // load course data from CSV file
    loadFromCSV();
  // display the mainn menu unitl user choose to exit
    while (true) {
        std::cout << "\n----- Course Management System -----\n1. Student\n2. Admin\n3. Exit\n";
        int choice;
        std::cout << "Enter your choice [1, 2, 3]: ";
        std::cin >> choice;
        std::cin.ignore(10000, '\n');
      //launch selected interface
        if (choice == 1) { Interface* screen = new StudentInterface; screen->run(); delete screen; }
        else if (choice == 2) { Interface* screen = new AdminInterface; screen->run(); delete screen; }
        else if (choice == 3) break;
        else std::cout << "Invalid choice. Please try again.\n";
    }
  // release dynamiccally allocated memory
    delete[] StoreDepartments;
    return 0;
}
