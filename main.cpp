#include <iostream>
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <cassert> // Unit Testing

using namespace std;

// Prototypes
void unitTesting();

int main() {
	roster classRoster;

	// Populate the roster with students
	classRoster.createSampleStudents();


	// Print all
	cout << "Roster" << endl;
	cout << "----------" << endl;
	classRoster.printAll();
	cout << endl;
	cout << endl;


	// Invalid emails
	classRoster.printInvalidEmails();
	cout << endl;
	cout << endl;


	// Average days in class per student
	cout << "Student's days in class average" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		string studentId = "";
		studentId = classRoster.classRosterArray[i]->getId();
		
		cout << "Student " << studentId << ": ";
		classRoster.printAverageDaysInCourse(studentId);
	}
	cout << endl;
	cout << endl;


	// Roster by degree
	cout << "Roster by SOFTWARE degree" << endl;
	cout << "-------------------------" << endl;
	classRoster.printByDegreeProgram(degreeProgram::SOFTWARE);
	cout << endl;
	cout << endl;


	// Removing student "A3"
	cout << "Delete student \"A3\"" << endl;
	cout << "-------------------" << endl;
	classRoster.remove("A3");
	cout << endl;
	cout << endl;


	// Print all
	cout << "Roster" << endl;
	cout << "----------" << endl;
	classRoster.printAll();
	cout << endl;
	cout << endl;


	//Removing student "A3" again
	cout << "Delete student \"A3\" again" << endl;
	cout << "---------------------------" << endl;
	classRoster.remove("A3");
	cout << endl;
	cout << endl;

	// Unit testing
	//unitTesting();

	// Clean up
	classRoster.clearMemory();

	return 0;
}

// Unit testing
void unitTesting() {
	student testStudent;
	roster testRoster;
	testRoster.createSampleStudents();


	// START OF TESTING
	cout << endl;
	cout << endl;
	cout << endl << "***** Testing starting *****" << endl;

	// student Test constructor/Defaults
	assert(testStudent.getId() == "-");
	assert(testStudent.getFirstName() == "-");
	assert(testStudent.getLastName() == "-");
	assert(testStudent.getEmail() == "-");
	assert(testStudent.getAge() == 0);
	assert(testStudent.getDegreeString() == "UNKNOWN");
	unsigned short* daysToCompleteCourses = testStudent.getDaysToCompleteCourses();
	string daysToCompleteCoursesString = to_string(daysToCompleteCourses[0]) + ", " + (to_string(daysToCompleteCourses[1])) + ", " + (to_string(daysToCompleteCourses[2]));
	assert(daysToCompleteCoursesString == "0, 0, 0");

	// student::getId()
	testStudent.setId("");
	assert(testStudent.getId() == "");

	testStudent.setId(" ");
	assert(testStudent.getId() == " ");

	testStudent.setId("-2");
	assert(testStudent.getId() == "-2");

	testStudent.setId("A2");
	assert(testStudent.getId() == "A2");


	// student::getAge()
	testStudent.setAge(numeric_limits<unsigned short>::min()); // Age minimum
	assert(testStudent.getAge() == numeric_limits<unsigned short>::min());

	testStudent.setAge(numeric_limits<unsigned short>::max()); // Age maximum
	assert(testStudent.getAge() == numeric_limits<unsigned short>::max());

	testStudent.setAge(40);
	assert(testStudent.getAge() == 40);


	// student::getDaysToCompleteCourses()
	testStudent.setDaysToCompleteCourses(2, 30, 200);
	daysToCompleteCourses = testStudent.getDaysToCompleteCourses();
	daysToCompleteCoursesString = to_string(daysToCompleteCourses[0]) +", " +(to_string(daysToCompleteCourses[1])) +", " +(to_string(daysToCompleteCourses[2]));
	assert(daysToCompleteCoursesString == "2, 30, 200");


	// student::getFirstName()
	testStudent.setFirstName("A-b C d");
	assert(testStudent.getFirstName() == "A-b C d");

	testStudent.setFirstName("Nelson");
	assert(testStudent.getFirstName() == "Nelson");


	// student::getLastName()
	testStudent.setLastName("A-b C d");
	assert(testStudent.getLastName() == "A-b C d");

	testStudent.setLastName("Araujo");
	assert(testStudent.getLastName() == "Araujo");


	// student::getEmail()
	testStudent.setEmail("A-b C d@test.com");
	assert(testStudent.getEmail() == "A-b C d@test.com");

	testStudent.setEmail("narauj4@wgu.edu");
	assert(testStudent.getEmail() == "narauj4@wgu.edu");


	// student::getDegree()
	testStudent.setDegree(degreeProgram::SECURITY);
	assert(testStudent.getDegreeString() == "SECURITY");

	testStudent.setDegree(degreeProgram::NETWORK);
	assert(testStudent.getDegreeString() == "NETWORK");

	testStudent.setDegree(degreeProgram::SOFTWARE);
	assert(testStudent.getDegreeString() == "SOFTWARE");

	testStudent.setDegree(degreeProgram::NETWORK);
	assert(testStudent.getDegreeString() == "NETWORK");


	// student::getRecord()
	testStudent.setId("ID");
	testStudent.setFirstName("FIRST");
	testStudent.setLastName("LAST");
	testStudent.setEmail("EMAIL@WGU.EDU");
	testStudent.setAge(99);
	testStudent.setDaysToCompleteCourses(22, 22, 33);
	testStudent.setDegree(degreeProgram::SOFTWARE);

	assert(testStudent.getRecord() == "ID	First Name: FIRST	Last Name: LAST	Age:99	daysInCourse: 22, 22, 33 	Degree Program: SOFTWARE");


	// roster::remove()
	//testRoster.remove("A3");
	//testRoster.remove("A3");

	// roster::printAll()
	//testRoster.printAll();

	// roster::printAverageDaysInCourse()
	//testRoster.printAverageDaysInCourse("A1");

	// roster::printInvalidEmails()
	//testRoster.printInvalidEmails();

	// roster::printByDegreeProgram
	//testRoster.printByDegreeProgram(degreeProgram::NETWORK);
	//testRoster.printByDegreeProgram(degreeProgram::SECURITY);
	//testRoster.printByDegreeProgram(degreeProgram::SOFTWARE);
	//testRoster.printByDegreeProgram(degreeProgram::UNKNOWN);

	// Clean Up
	testRoster.clearMemory();

	// END OF TESTING
	cout << endl << "***** Testing completed *****" << endl;

}
