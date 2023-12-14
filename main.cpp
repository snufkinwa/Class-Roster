#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

    std::cout << R"(
 /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$$
 /$$__  $$ /$$__  $$ /$$__  $$|_____ $$/
| $$  \__/| $$  \ $$| $$  \__/     /$$/ 
| $$      |  $$$$$$/| $$$$$$$     /$$/  
| $$       >$$__  $$| $$__  $$   /$$/   
| $$    $$| $$  \ $$| $$  \ $$  /$$/    
|  $$$$$$/|  $$$$$$/|  $$$$$$/ /$$/     
 \______/  \______/  \______/ |__/ 
                                     
⠀)";
    std::cout << endl;
    // Print course information
    std::cout << "Scripting and Programing - Applications - C867" << endl;
    std::cout << "Programming Language: C++" << endl;
    std::cout << "Janay Harris" << endl;
    std::cout << "Student ID: 011097891" << endl;
    std::cout << endl;

    // Array of student data

    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Janay,Harris,jha2972@wgu.edu,32,42,24,11,SOFTWARE" };

    // Create a roster object
    Roster classRoster;
    Student s;

    // Parse and add student data to the roster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }

    // Print all students in the roster
    std::cout << "Displaying all students: " << endl;
    cout << "StudentID  \t| First Name\t| Last Name\t| Age\t| Days In Course\t| Degree Program\t|" << endl;
    classRoster.printAll();
    std::cout << endl;

    // Print invalid email addresses in the roster
    std::cout << "Displaying invalid emails: " << endl;
    classRoster.printInvalidEmails();
    std::cout << endl;

    // Print average days in course for each student
    for (int i = 0; i < 5; i++) {
        Student* studentPointer = classRoster.getClassRosterArray(i);
        string studentID = studentPointer->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    std::cout << endl;

    // Print students in a specific degree program
    std::cout << "Displaying students in Degree Program SOFTWARE: " << endl;
    cout << "StudentID  \t| First Name\t| Last Name\t| Age\t| Days In Course\t| Degree Program\t|" << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    std::cout << endl;

    // Remove a student from the roster
    std::cout << "Removing A3" << endl;
    classRoster.remove("A3");
    std::cout << endl;

    // Print all students in the roster
    std::cout << "Displaying all students: " << endl;
    cout << "StudentID  \t| First Name\t| Last Name\t| Age\t| Days In Course\t| Degree Program\t|" << endl;
    classRoster.printAll();
    std::cout << endl;

    // Try to remove a student that doesn't exist
    std::cout << "Removing A3 " << endl;
    classRoster.remove("A3");
    std::cout << endl;

    return 0;
}