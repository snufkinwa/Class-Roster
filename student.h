#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include <string>
#include <vector>
#include "degree.h" // Include the degree.h header file

using std::string;
using std::vector;
using std::cout; 

class Student {
private:
    // Variable to store 
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    vector<int> daysToCompleteCourses; 
    DegreeProgram degreeprogram;

public:
    //Constructor with Parameters 
    Student(string id, string first,string last, string email, int studentAge, const vector<int> days, DegreeProgram degreeprogram);

    // Accessors (getters)
    int getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    vector<int> getDaysToCompleteCourses() const;
    DegreeProgram getDegreeProgram() const;

    // Mutators (setters)
    void setStudentID(int id);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmailAddress(string email);
    void setAge(int studentAge);
    void setDaysToCompleteCourses(const vector<int>& days);
    void setDegreeProgram(DegreeProgram degreeprogram);

    // Print student data
    void print();

};
#endif