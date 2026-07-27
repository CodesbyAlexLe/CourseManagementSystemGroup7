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
