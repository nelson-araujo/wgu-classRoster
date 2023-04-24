#include "student.h"


// Accessors
string student::getId() const {
	return id;
}

unsigned short student::getAge() const {
	return age;
}

unsigned short* student::getDaysToCompleteCourses() {
	return daysToCompleteCourses;

}

string student::getFirstName() const {
	return firstName;
}

string student::getLastName() const {
	return lastName;
}

string student::getEmail() const {
	return email;
}

degreeProgram student::getDegree() const {
	return degree;
}

string student::getDegreeString() const {
	switch (degree) {
	case degreeProgram::SECURITY:
		return "SECURITY";
		break;

	case degreeProgram::NETWORK:
		return "NETWORK";
		break;

	case degreeProgram::SOFTWARE:
		return "SOFTWARE";
		break;

	case degreeProgram::UNKNOWN:
		return "UNKNOWN";
		break;

	default:
		return "Error, unknown degree type.";
		break;
	}
}

string student::getRecord() const {
	string studentRecord = "";

	studentRecord.append(getId());
	studentRecord.append("\tFirst Name: ");
	studentRecord.append(getFirstName());
	studentRecord.append("\tLast Name: ");
	studentRecord.append(getLastName());
	//studentRecord.append("\tEmail: ");
	//studentRecord.append(getEmail());
	studentRecord.append("\tAge:");
	studentRecord.append( to_string(getAge()) );
	studentRecord.append("\tdaysInCourse: ");
	// Append days to complete courses
	for (int i = 0; i < (sizeof(daysToCompleteCourses) / sizeof(daysToCompleteCourses[0]) - 1); i++) {
		studentRecord.append( (to_string(daysToCompleteCourses[i])) ); // Must convert the int to string
		if (i < (sizeof(daysToCompleteCourses) / sizeof(daysToCompleteCourses[0])) - 2) { // Add comma after each except for the last entry
			studentRecord.append(", ");
		}
	}
	studentRecord.append(" \tDegree Program: ");
	studentRecord.append(getDegreeString());

	return studentRecord;
};

void student::printDaysToCompleteCourses() const{
	for (int i = 0; i < (sizeof(daysToCompleteCourses) / sizeof(daysToCompleteCourses[0]) - 1); i++) {
		cout << (to_string(daysToCompleteCourses[i])); // Must convert the int to string
		if (i < (sizeof(daysToCompleteCourses) / sizeof(daysToCompleteCourses[0])) - 2) { // Add comma after each except for the last entry
			cout << ", ";
		}
	}
}

void student::printRecord() const {
	cout << getRecord() << endl;
}

// Mutators
void student::setId(string tempId) {
id = tempId;

}

void student::setAge(unsigned short tempAge) {
	age = tempAge;
}

void student::setDaysToCompleteCourses(unsigned short course1, unsigned short course2, unsigned short course3) {
	daysToCompleteCourses[0] = course1;
	daysToCompleteCourses[1] = course2;
	daysToCompleteCourses[2] = course3;
}

void student::setFirstName(string tempFirstName) {
	firstName = tempFirstName;
}

void student::setLastName(string tempLastName) {
	lastName = tempLastName;
}

void student::setEmail(string tempEmail) {
	email = tempEmail;
}

void student::setDegree(degreeProgram tempDegree) {
	degree = tempDegree;
}

// Constructor
student::student() {
	id = "-";
	age = 0;
	daysToCompleteCourses[0] = 0;
	daysToCompleteCourses[1] = 0;
	daysToCompleteCourses[2] = 0;
	firstName = "-";
	lastName = "-";
	email = "-";
	degree = degreeProgram::UNKNOWN;

	return;
}