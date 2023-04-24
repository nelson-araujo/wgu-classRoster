#pragma once // Alternative to ifndef

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

const string studentDataTable[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Nelson,Araujo,narauj4@wgu.edu,40,11,22,33,SOFTWARE"
};

class roster {
	public:
		// Constructors
		void createSampleStudents();
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, unsigned int daysInCourse1, unsigned int daysInCourse2, unsigned int daysInCourse3, degreeProgram degreeprogram);


		// Mutators
		string parseNextStudentData(string& remainingStudentData, int& nextCommaPosition);
		void remove(string studentID);

		// Accessors
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(degreeProgram degreeProgram);

		// Destructors
		void clearMemory();

		student* classRosterArray[sizeof(studentDataTable) / sizeof(studentDataTable[0])] = { NULL }; // Size is based on the studentDataTable[] size.
	
private:
		
};