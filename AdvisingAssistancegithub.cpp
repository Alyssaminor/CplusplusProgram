#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class Course {
private:
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;

public:
    // Constructors
    Course() {}

    Course(const std::string& number, const std::string& title) : courseNumber(number), courseTitle(title) {}

    // Setters and getters
    void setCourseNumber(const std::string& number) { courseNumber = number; }
    void setCourseTitle(const std::string& title) { courseTitle = title; }
    void addPrerequisite(const std::string& prereq) { prerequisites.push_back(prereq); }

    std::string getCourseNumber() const { return courseNumber; }
    std::string getCourseTitle() const { return courseTitle; }
    std::vector<std::string> getPrerequisites() const { return prerequisites; }

    // Function to print the course information
    void printCourseInfo() const {
        std::cout << courseNumber << ", " << courseTitle << std::endl;
        if (!prerequisites.empty()) {
            std::cout << "Prerequisites: ";
            for (size_t i = 0; i < prerequisites.size(); ++i) {
                std::cout << prerequisites[i];
                if (i != prerequisites.size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }

    // Overloading the '<' operator for sorting purposes
    bool operator<(const Course& other) const {
        return courseNumber < other.courseNumber;
    }
};

// Global variable to hold all courses
std::vector<Course> courses;

// Function prototypes
void loadCoursesFromFile();
void displayMenu();
void handleMenuChoice();
void printCourseList();
void printCourseInfo();

int main() {
    while (true) {
        displayMenu();
        handleMenuChoice();
    }
    return 0;
}

void loadCoursesFromFile() {
    std::cout << "Enter the filename: ";
    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        size_t pos = line.find(',');
        std::string number = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        std::string title = line.substr(0, pos);
        line.erase(0, pos + 1);

        Course course(number, title);

        while ((pos = line.find(',')) != std::string::npos) {
            std::string prereq = line.substr(0, pos);
            course.addPrerequisite(prereq);
            line.erase(0, pos + 1);
        }
        if (!line.empty()) {
            course.addPrerequisite(line);
        }

        courses.push_back(course);
    }

    file.close();
    std::cout << "Courses loaded successfully!" << std::endl;
}

void displayMenu() {
    std::cout << "\n1. Load Data Structure." << std::endl;
    std::cout << "2. Print Course List." << std::endl;
    std::cout << "3. Print Course." << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "What would you like to do? ";
}

void handleMenuChoice() {
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        loadCoursesFromFile();
        break;
    case 2:
        printCourseList();
        break;
    case 3:
        printCourseInfo();
        break;
    case 9:
        std::cout << "Exiting..." << std::endl;
        exit(0);
    default:
        std::cout << "Invalid option. Try again." << std::endl;
        break;

    }
}

void printCourseList() {
    // Sorting the course list alphanumerically
    std::sort(courses.begin(), courses.end());

    std::cout << "\nCourse List:\n";
    for (const auto& course : courses) {
        std::cout << course.getCourseNumber() << ", " << course.getCourseTitle() << std::endl;
    }
}

void printCourseInfo() {
    std::string courseNum;
    std::cout << "Enter the course number: ";
    std::cin >> courseNum;

    // Finding the course based on the course number
    auto it = std::find_if(courses.begin(), courses.end(), [&courseNum](const Course& course) {
        return course.getCourseNumber() == courseNum;
        });

    if (it != courses.end()) {
        it->printCourseInfo();
    }
    else {
        std::cout << "Course not found!" << std::endl;
    }
}
