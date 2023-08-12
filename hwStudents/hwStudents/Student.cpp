#include "Student.h"

// Constructor: Initializes a Student object with a name
Student::Student(const std::string& name) : name(name) {}

// Adds a grade to the student's record
void Student::addGrade(double grade) {
    grades.push_back(grade);
}

// Calculates and returns the average grade for the student
double Student::calculateAverageGrade() const {
    if (grades.empty()) {
        return 0.0;  // Return 0.0 if there are no grades to avoid division by zero
    }
    double sum = 0.0;
    for (double grade : grades) {
        sum += grade;  // Summing up the grades
    }
    return sum / grades.size();  // Calculating the average by dividing sum by the number of grades
}

// Getter method to retrieve the name of the student
std::string Student::getName() const {
    return name;
}

// Getter method to retrieve the list of grades for the student
const std::vector<double>& Student::getGrades() const {
    return grades;
}
