#pragma once
#include <vector>
#include "course.h"

class Cart {
public:
    void addCourse(const Course& course);
    bool isEmpty() const;
    void clear();
    void display() const;
    const std::vector<Course>& getItems() const;

private:
    std::vector<Course> items;
};
