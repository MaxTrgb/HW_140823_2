#include "Group.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor: Initializes a Group object with a name
Group::Group(const string& name) : name(name) {}

// Adds a student to the group
void Group::addStudent(const Student& student) {
    students.push_back(student);
}

// Adds a subject to the group
void Group::addSubject(const Subject& subject) {
    subjects.push_back(subject);
}

// Reads grades for students and subjects from a file
void Group::readGradesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string studentName;
        double grade;

        getline(iss, studentName, ':'); // Read until the colon delimiter
        Student* student = findStudent(studentName);
        if (student == nullptr) {
            cerr << "Student not found: " << studentName << endl;
            continue;
        }

        while (iss >> grade) {
            student->addGrade(grade); // Add the read grade to the student's record
        }
    }
}

// Calculates average grades for students, subjects, and the entire group
void Group::calculateAverages() {
    // Calculate average grades for each student
    for (Student& student : students) {
        studentAverages.push_back(student.calculateAverageGrade());
    }

    // Calculate average grades for each subject
    for (size_t subjectIndex = 0; subjectIndex < subjects.size(); ++subjectIndex) {
        double subjectSum = 0.0;
        int numGrades = 0;

        // Iterate through students and collect grades for the current subject
        for (const Student& student : students) {
            const vector<double>& grades = student.getGrades();
            if (subjectIndex < grades.size()) {
                subjectSum += grades[subjectIndex];
                numGrades++;
            }
        }

        // Calculate the average grade for the subject if there are grades
        if (numGrades > 0) {
            subjectAverages.push_back(subjectSum / numGrades);
        }
    }

    // Calculate the average grade for the entire group
    groupAverage = 0.0;
    for (double average : studentAverages) {
        groupAverage += average;
    }
    groupAverage /= students.size();
}

// Prints individual student grades for each subject
void Group::printStudentGrades() const {
    cout << "First grade - Math\nSecond grade - Physics\nThird grade - Programming\n";
    cout << "\nStudent Grades:\n";
    for (const Student& student : students) {
        cout << student.getName() << ": ";
        for (double grade : student.getGrades()) {
            cout << grade << " ";
        }
        cout << endl;
    }
}

// Prints average grades for each student, each subject, and the entire group
void Group::printAverages() const {
    cout << "\nAverage Grades:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << students[i].getName() << ": " << studentAverages[i] << endl;
    }

    cout << "\nAverage Grades in Subjects:\n";
    for (size_t i = 0; i < subjects.size(); ++i) {
        cout << subjects[i].getName() << ": " << subjectAverages[i] << endl;
    }

    cout << "\nAverage Group Score: " << groupAverage << endl;
}

// Helper method to find a student by name
Student* Group::findStudent(const string& name) {
    for (Student& student : students) {
        if (student.getName() == name) {
            return &student;
        }
    }
    return nullptr; // Return nullptr if the student is not found
}
