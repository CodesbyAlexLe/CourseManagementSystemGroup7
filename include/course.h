#pragma once

class Course {
private:
    char number[20];
    char name[100];
    char schedule[10];
    double price;

public:
    Course();
    Course(const char* number, const char* name, const char* schedule, double price);
    const char* getNumber() const;
    const char* getName() const;
    const char* getSchedule() const;
    double getPrice() const;
    void display() const;
};
