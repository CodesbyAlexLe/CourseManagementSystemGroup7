#include "cart.h"
#include <iostream>

void Cart::addCourse(const Course& course) {
    items.push_back(course);
}

bool Cart::isEmpty() const {
    return items.empty();
}

void Cart::clear() {
    items.clear();
}

void Cart::display() const {
    if (items.empty()) {
        std::cout << "Your cart is empty.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); i++) {
        std::cout << (i + 1) << ". ";
        items[i].display();
        std::cout << "\n";
    }
}

const std::vector<Course>& Cart::getItems() const {
    return items;
}

