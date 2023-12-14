#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

Student* classRosterArray = new Student[5];
int n = 0;

Roster::Roster() {

}

// Add a student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree) {

	Student* s = new Student(studentID, firstName, lastName, emailAddress, age,
		daysToComplete1, daysToComplete2, daysToComplete3, degree);
	classRosterArray[n] = s;
	n++;
}

// Remove a student from the roster
void Roster::remove(string studentID) {
	int i = 0;
	int studentIndex = -1;
	while (i < 5) {
		Student s = *classRosterArray[i];
		if (s.getStudentID() == studentID) {
			studentIndex = i;
			*classRosterArray[i] = Student();
		}
		i++;
	}
	if (studentIndex == -1) {
		std::cout <<  studentID << " was not found.";
	}
}

// Print information for all students in the roster
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		Student s = *classRosterArray[i];
		if (s.getStudentID() != "") {
			s.print(*classRosterArray[i]);
		}
	}
}

// Print the average number of days in a course for a given student
void Roster::printAverageDaysInCourse(string studentID) {
	int i = 0;
	int* daysArray;
	int days = 0;
	while (i < 5) {
		Student s = *classRosterArray[i];
		if (s.getStudentID() == studentID) {
			daysArray = s.getDaysToComplete();
			break;
		}
		else {
			daysArray = {};
		}
		i++;
	}
	for (int j = 0; j < 3; j++) {
		days = days + daysArray[j];
	}
	std::cout << "Average Days in Course for " << studentID << " is " << days / 3 << endl;
}

// Print all invalid email addresses in the roster
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		Student s = *classRosterArray[i];
		string email = s.getEmailAddress();
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			cout << "The email for student " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is not valid " << email << endl;
		}
	}
}

// Print information for all students in a specified degree program
void Roster::printByDegreeProgram(enum DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		Student s = *classRosterArray[i];
		if (s.getDegreeProgram() == degreeProgram) {
			s.print(s);
		}
	}
}

// Parse a string of student data and add the student to the roster
void Roster::parse(string studentData) {
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;

	if (strDegreeProgram == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (strDegreeProgram == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3, degree);
}

// Get a pointer to the Student object at a specified index in the classRosterArray
Student* Roster::getClassRosterArray(int i) {
	return classRosterArray[i];
}

Roster::~Roster() {
	delete* classRosterArray;
	std::cout << "DONE";
}