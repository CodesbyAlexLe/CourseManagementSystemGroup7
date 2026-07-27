#include <string>
#include <vector>
#include "DataStore.h"
#include "CartItem.h"

class Interface {
public:
    Interface(const std::string& dataFile);
    void run();

private:
    DataStore store;
    std::vector<CartItem> cart;
    std::string dataFilePath;

    //Initial Menu
    void showInitialMenu();

    //Admin Interface
    void adminMenu();
    void listDepartments();
    void addDepartment();
    void addCourseToDepartment();
    void saveChanges();

    // Student Interface
    void studentMenu();
    void showCart();
    void checkout();
    void browseDepartments();
    void listCoursesInDepartment(Department& dept);
    void addCourseToCart(Department& dept);

    // Input Helpers (all loop until a valid value is entered
    int getMenuChoice(int minVal, int maxVal, const std::string& prompt);
    std::string getNonEmptyString(const std::string& prompt);
    double getPositiveDouble(const std::string& prompt);
};
