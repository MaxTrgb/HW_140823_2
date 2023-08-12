#include "Subject.h"

// Constructor: Initializes a Subject object with a name
Subject::Subject(const std::string& name) : name(name) {}

// Getter method to retrieve the name of the subject
std::string Subject::getName() const {
    return name;
}
