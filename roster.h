#ifndef ROSTER_H
#define ROSTER_H 

#include <string>
#include "student.h"

class Roster {
public:
	Roster(); // Constructor
	~Roster(); // Destructor

	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree); // Add a student to the roster

	void remove(string studentID); // Remove a student from the roster

	void printAll(); // Print information for all students in the roster

	void printAverageDaysInCourse(string studentID); // Print the average number of days in a course for a given student

	void printInvalidEmails(); // Print all invalid email addresses in the roster

	void printByDegreeProgram(enum DegreeProgram degreeProgram); // Print information for all students in a specified degree program

	void parse(string studentData); // Parse a string of student data and add the student to the roster

	Student* getClassRosterArray(int i); // Get a pointer to the Student object at a specified index in the classRosterArray

private:
	int count; // Number of students in the roster
	Student* classRosterArray[5]; // Array of pointers to Student objects (fixed size of 5)
};

#endif // !ROSTER_H



