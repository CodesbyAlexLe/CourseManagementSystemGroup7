#include "StudentInterface.h"
#include <iostream>

StudentInterface::StudentInterface(std::vector<Department>& departments)
    : departments(departments)
{
}


// display the main menu and process user selections
void StudentInterface::run()
{
    int choice;
    do
    {
        std:: cout << "1. Show Cart\n";
        std:: cout << "2. Browse Departments\n";
        std:: cout << "3. Exit\n";
        choice = getMenuChoice(1, 3, "Enter your Choice [1, 2, 3]: ");

        switch (choice)
        {
            case 1:
                showCart();
                    break; 
            case 2:
                browseDepartments();
                    break;
            case 3:
                std::cout << "Goodbye\n";
                    break;
        }
            
    } while (choice != 3);
}

// display cart menu and allow the user to view or checkout
void StudentInterface::showCart()
{
    int choice;
    do
    {
        std:: cout << "1. List Courses\n";
        std:: cout << "2. Checkout\n";
        std:: cout << "3. Return to Main Menu\n";
        choice = getMenuChoice(1, 3, "Enter your Choice [1, 2, 3]: ");

        switch (choice)
        {
        case 1:
            cart.display();
                break;
        case 2:
            checkout();
                break;
        case 3:
            std::cout << "Returning to main menu\n";
            break;
        }
    } while (choice != 3);
}
// complete the purchase or notify the user if the cart is empty
void StudentInterface::checkout()
{
    if (cart.isEmpty())
    {
        std::cout << "No courses in the cart\n";
    }
    else
    {
        std::cout << "Thank you for your purchase\n";
        cart.clear();
    }
}
// display departaments and allow the user to select one
void StudentInterface::browseDepartments()
{
    int choice;
    int departmentNumber;
    do
    {
        std::cout << "1. List Courses of Departments\n";
        std::cout << "2. Go to back menu\n";
        choice = getMenuChoice(1, 2, "Enter your Choice [1, 2]: ");

        switch (choice)
        {
        case 1:
            // display available department
            for (int i = 0; i < departments.size(); i = i + 1)
            {
                std::cout << i + 1 << ". " << departments[i].name << "\n";

            }
            departmentNumber = getMenuChoice(0, departments.size(), "Enter department number [0 to go back]: ");
            if (departmentNumber != 0)
            {
                listCoursesInDepartment(departments[departmentNumber - 1]);
            }

            break;
        case 2:
            std::cout << "Returning to main menu\n";
            break;
        }
    } while (choice != 2);
}
// display courses in the selected departament
void StudentInterface::listCoursesInDepartment(Department& dept)
{
    int choice;
   
    do
    {
        // display available courses
        for (int i = 0; i < dept.courses.size(); i = i + 1)
        {
            std::cout << i + 1 << ". ";
            dept.courses[i].display();
        }

        std::cout << "1. Add to Cart a course\n";
        std::cout << "2. Go Back to Browse Departments Menu\n";
        choice = getMenuChoice(1, 2, "Enter your Choice[1, 2]: ");
        // procces user menu selection
        switch (choice)
        {
        case 1:
            
            addCourseToCart(dept);
            break;
        
        case 2:
        
            std::cout << "Returning to main menu\n";
            break;
        }
    } while (choice != 2);
}
// Allow the user to add a selected course to the shopping cart
void StudentInterface::addCourseToCart(Department& dept)
{
    int courseNumber;

    courseNumber = getMenuChoice(0, dept.courses.size(), "Enter course number [0 to go back]: ");
    if (courseNumber != 0)
    {
        // add the selected course to the cart
        cart.addCourse(dept.courses[courseNumber - 1]);
        std::cout << "Course added to cart.\n";
    }
}
