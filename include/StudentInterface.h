#pragma once
#include <vector>
#include "department.h"
#include "cart.h"

class StudentInterface {
public:
    StudentInterface(std::vector<Department>& departments);
    void run();

private:
    std::vector<Department>& departments;
    Cart cart;
