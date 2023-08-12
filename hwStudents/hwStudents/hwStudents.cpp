#include <iostream>
#include <fstream>
#include "Group.h"
#include "Student.h"
#include "Subject.h"
using namespace std;

int main() {
    // Create a group named "Group of Students"
    Group group("Group of Students");

    // Read students from Students.txt
    ifstream studentsFile("Students.txt");
    if (!studentsFile.is_open()) {
        cerr << "Error opening Students.txt" << endl;
        return 1;
    }
    string studentName;
    // Read each line (student name) from Students.txt
    while (getline(studentsFile, studentName)) {
        // Create a Student object with the extracted student name and add it to the group
        group.addStudent(Student(studentName));
    }
    studentsFile.close();

    // Read subjects from Subjects.txt
    ifstream subjectsFile("Subjects.txt");
    if (!subjectsFile.is_open()) {
        cerr << "Error opening Subjects.txt" << endl;
        return 1;
    }
    string subjectName;
    // Read each line (subject name) from Subjects.txt
    while (getline(subjectsFile, subjectName)) {
        // Create a Subject object with the extracted subject name and add it to the group
        group.addSubject(Subject(subjectName));
    }
    subjectsFile.close();

    // Read grades from Grades.txt and associate them with students and subjects
    group.readGradesFromFile("Grades.txt");

    // Calculate average grades for each student and subject
    group.calculateAverages();

    // Print student grades for each subject
    group.printStudentGrades();

    // Print average grades for each subject
    group.printAverages();

    return 0;
}
