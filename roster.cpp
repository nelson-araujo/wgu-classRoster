#include "roster.h"


// Constructors
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, unsigned int daysInCourse1, unsigned int daysInCourse2, unsigned int daysInCourse3, degreeProgram degree) {
	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		// Find the first available roster slot for a new student
		if (classRosterArray[i] == NULL) {
			classRosterArray[i] = new student; // Create a new student

			classRosterArray[i]->setId(studentID);
			classRosterArray[i]->setFirstName(firstName);
			classRosterArray[i]->setLastName(lastName);
			classRosterArray[i]->setEmail(emailAddress);
			classRosterArray[i]->setAge(age);
			classRosterArray[i]->setDaysToCompleteCourses(daysInCourse1, daysInCourse2, daysInCourse3);
			classRosterArray[i]->setDegree(degree);

			break; // Exit out of loop to not overwrite slots further down
		}
	}
}

// Mutators
void roster::remove(string studentID) {
	int record = NULL;
	string userId = "";

	
	// Find student record
	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		if (classRosterArray[i] != NULL && classRosterArray[i]->getId() == studentID) {
			userId = classRosterArray[i]->getId();
			record = i;
		}
	}

	// Delete record
	if (record != NULL && classRosterArray[record] != NULL) {
		classRosterArray[record] = NULL; // Delete from roster
		delete classRosterArray[record]; // Release memory
		cout << "Deleted student \"" << userId << "\"" << endl;
	} else {
		cout << "Student \"" << studentID << "\" not found." << endl;
	}
}

// Accessors
void roster::createSampleStudents() {
	string studentID="", firstName="", lastName="", emailAddress="";
	int age=0;
	unsigned int daysInCourse1=0, daysInCourse2=0, daysInCourse3=0;
	degreeProgram degree=degreeProgram::UNKNOWN;

	int nextCommaPosition=0;
	string remainingStudentData="";

	// Parse student string
	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]) ; i++) {
		remainingStudentData = studentDataTable[i]; // Start with all student data information

		studentID = parseNextStudentData(remainingStudentData, nextCommaPosition);
		firstName = parseNextStudentData(remainingStudentData, nextCommaPosition);
		lastName = parseNextStudentData(remainingStudentData, nextCommaPosition);
		emailAddress = parseNextStudentData(remainingStudentData, nextCommaPosition);
		age = stoi(parseNextStudentData(remainingStudentData, nextCommaPosition));
		daysInCourse1 = stoul(parseNextStudentData(remainingStudentData, nextCommaPosition)); // Get days in course and convert the string to an unsigned integer
		daysInCourse2 = stoul(parseNextStudentData(remainingStudentData, nextCommaPosition)); // Get days in course and convert the string to an unsigned integer
		daysInCourse3 = stoul(parseNextStudentData(remainingStudentData, nextCommaPosition)); // Get days in course and convert the string to an unsigned integer
		if (parseNextStudentData(remainingStudentData, nextCommaPosition) == "SECURITY") {
			degree = degreeProgram::SECURITY;
		}
		else if (parseNextStudentData(remainingStudentData, nextCommaPosition) == "NETWORK") {
			degree = degreeProgram::NETWORK;
		}
		else if (parseNextStudentData(remainingStudentData, nextCommaPosition) == "SOFTWARE") {
			degree = degreeProgram::SOFTWARE;
		}
		else if (parseNextStudentData(remainingStudentData, nextCommaPosition) == "UNKNOWN" || parseNextStudentData(remainingStudentData, nextCommaPosition) == "") {
			degree = degreeProgram::UNKNOWN;
		}

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	}
}

string roster::parseNextStudentData(string& remainingStudentData, int& nextCommaPosition) {
	string studentData = "";

	// Find the enxt comma position
	nextCommaPosition = remainingStudentData.find(",");

	// Extract data
	studentData = remainingStudentData.substr(0, nextCommaPosition);
	//return "AAA";

	// Update the string to only include the remaining data
	remainingStudentData = remainingStudentData.substr(nextCommaPosition + 1, remainingStudentData.size());

	return studentData;
}

void roster::printAll() {
	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->printRecord();
		}
	}
}

void roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		if (classRosterArray[i] != NULL && classRosterArray[i]->getId() == studentID) { // Find the student record
			unsigned short* daysInCourse = classRosterArray[i]->getDaysToCompleteCourses();
			unsigned short totalDaysInCourse = NULL;

			// Calculating total
			for (int i = 0; i < NUM_COURSES-1 ; i++) {
				totalDaysInCourse += daysInCourse[i];
			}
			
			// Printing average
			cout << "Average days in courses: " << totalDaysInCourse/(NUM_COURSES-1) << endl;
		}
	}

}

void roster::printInvalidEmails() {
	cout << "Invalid Email(s)" << endl;
	cout << "----------------" << endl;

	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		string email = classRosterArray[i]->getEmail();
		if (email.find(' ') != string::npos) {
			cout << email << "\t- Contains space(s)" << endl;
		} else if (email.find('@') == string::npos) {
			cout << email << "\t- Doesn't contain \'@\'" << endl;
		} else if (email.find('.') == string::npos) {
			cout << email << "\t- Doesn't contain \'.\'" << endl;
		}
	}


}

void roster::printByDegreeProgram(degreeProgram degreeProgram) {
	cout << "Student(s) in ";
	switch (degreeProgram) {
	case degreeProgram::SECURITY:
		cout << "SECURITY" << endl;
		break;

	case degreeProgram::NETWORK:
		cout << "NETWORK" << endl;
		break;

	case degreeProgram::SOFTWARE:
		cout << "SOFTWARE" << endl;
		break;

	case degreeProgram::UNKNOWN:
		cout << "UNKNOWN" << endl;
		break;

	default:
		cout << "Error, unknown degree type." << endl;
		break;
	}
	cout << "----------------------" << endl;

	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) {
		if (classRosterArray[i]->getDegree() == degreeProgram) {
			classRosterArray[i]->printRecord();
		}
	}
	cout << endl;
}

// Desctructors
void roster::clearMemory() {

	for (int i = 0; i < sizeof(studentDataTable) / sizeof(studentDataTable[0]); i++) { // Destroy all students
		if (classRosterArray[i] != NULL) {
			delete classRosterArray[i];
		}
	}
}




