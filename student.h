#ifndef STUDENT_H
#define STUDENT_H 

#include <string>
#include "degree.h"

using std::string;

class Student {
public:
    // Default constructor
    Student();

    // Parameterized constructor
    Student(string ID, string first, string last, string email, int studentAge,
        int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree);

    // Setter methods for member variables
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setDaysToComplete(int[3]);
    void setDegreeProgram(enum DegreeProgram);

    // Getter methods for member variables
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToComplete();
    enum DegreeProgram getDegreeProgram();

    // Print method to display student information
    void print(Student);

private:
    // Member variables
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    enum DegreeProgram degree;
};


#endif // !STUDENT_H


