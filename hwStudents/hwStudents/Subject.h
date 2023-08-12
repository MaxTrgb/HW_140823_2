#pragma once

#include <string>

class Subject {
public:
    // Constructor: Initializes the Subject object with a name
    Subject(const std::string& name);

    // Getter method to retrieve the name of the subject
    std::string getName() const;

private:
    std::string name;  // Private member variable to store the name of the subject
};
