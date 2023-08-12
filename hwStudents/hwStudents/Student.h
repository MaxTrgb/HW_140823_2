#pragma once

#include <string>
#include <vector>
using namespace std;

class Student {
public:
    // Constructor: Initializes the Student object with a name
    Student(const string& name);

    // Adds a grade to the student's record
    void addGrade(double grade);

    // Calculates and returns the average grade for the student
    double calculateAverageGrade() const;

    // Getter method to retrieve the name of the student
    string getName() const;

    // Getter method to retrieve the list of grades for the student
    const vector<double>& getGrades() const;

private:
    string name;               // Private member variable to store the name of the student
    vector<double> grades;     // Private member variable to store the list of grades for the student
};
