#pragma once

#include <string>
#include <vector>
#include "Subject.h"
#include "Student.h"
using namespace std;

class Group {
public:
    // Constructor: Initializes the Group object with a name
    Group(const string& name);

    // Adds a student to the group
    void addStudent(const Student& student);

    // Adds a subject to the group
    void addSubject(const Subject& subject);

    // Reads grades for students and subjects from a file
    void readGradesFromFile(const string& filename);

    // Calculates average grades for students, subjects, and the entire group
    void calculateAverages();

    // Prints individual student grades for each subject
    void printStudentGrades() const;

    // Prints average grades for each subject and the entire group
    void printAverages() const;

private:
    // Helper method to find a student by name
    Student* findStudent(const string& name);

    string name;                  // Private member variable to store the name of the group
    vector<Student> students;     // Private member variable to store the list of students in the group
    vector<Subject> subjects;     // Private member variable to store the list of subjects in the group
    vector<double> studentAverages;   // Private member variable to store average grades for each student
    vector<double> subjectAverages;   // Private member variable to store average grades for each subject
    double groupAverage;              // Private member variable to store the average grade for the entire group
};
