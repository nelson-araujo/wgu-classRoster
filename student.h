#pragma once // Alternative to ifndef

#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"

using namespace std;

const unsigned short NUM_COURSES = 4; // 3 usable elements

class student {
	public:
		//Constructor
		student();

		// Mutators
		void setId(string tempId);
		void setAge(unsigned short tempAge);
		void setDaysToCompleteCourses(unsigned short course1, unsigned short course2, unsigned short course3);
		void setFirstName(string tempFirstName);
		void setLastName(string tempLastName);
		void setEmail(string tempEmail);
		void setDegree(degreeProgram tempDegree);

		// Accessors
		string getId() const;
		unsigned short getAge() const;
		unsigned short* getDaysToCompleteCourses();
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		degreeProgram getDegree() const;
		string getDegreeString() const;
		string getRecord() const;
		void printDaysToCompleteCourses() const;
		void printRecord() const;

	private:
		string id;
		unsigned short age;
		unsigned short daysToCompleteCourses[NUM_COURSES];
		string firstName;
		string lastName;
		string email;
		degreeProgram degree;

};