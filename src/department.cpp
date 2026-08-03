#include "department.h"
#include <fstream>
#include <sstream>

Department::Department() : name("") {}
Department::Department(const std::string& n) : name(n) {}

Course* Department::findCourse(const std::string& courseNumber) {
    for (auto& c : courses) {
        if (c.courseNumber == courseNumber) {
            return &c;
        }
    }
    return nullptr;
}

Department* findDepartment(std::vector<Department>& departments, const std::string& name) {
    for (auto& d : departments) {
        if (d.name == name) {
            return &d;
        }
    }
    return nullptr;
}

// Splits a CSV line into fields (simple comma split, no quoted-field support)
static std::vector<std::string> splitCSVLine(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    while (std::getline(ss, field, ',')) {
        fields.push_back(field);
    }
    return fields;
}

bool loadDepartmentsFromCSV(const std::string& filename, std::vector<Department>& departments) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        // No existing file yet is not a fatal error - start with an empty catalog
        return false;
    }

    departments.clear();
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::vector<std::string> fields = splitCSVLine(line);
        if (fields.size() < 5) continue;

        double price;
        try {
            price = std::stod(fields[4]);
        }
        catch (...) {
            price = 0.0;
        }
        Course course(fields[1], fields[2], fields[3], price);

        Department* dept = findDepartment(departments, fields[0]);
        if (!dept) {
            departments.push_back(Department(fields[0]));
            dept = &departments.back();
        }
        dept->courses.push_back(course);
    }

    file.close();
    return true;
}

bool saveDepartmentsToCSV(const std::string& filename, const std::vector<Department>& departments) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& dept : departments) {
        for (const auto& course : dept.courses) {
            file << dept.name << ","
                << course.courseNumber << ","
                << course.courseName << ","
                << course.schedule << ","
                << course.price << "\n";
        }
    }

    file.close();
    return true;
}
