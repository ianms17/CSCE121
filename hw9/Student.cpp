#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string student_id, string name) 
	:
	id(student_id),
	name(name) {
}

string Student::get_id() {
	return this->id;
}

string Student::get_name() {
	return this->name;
}

void Student::addCourse(string course_id) {
	for (unsigned int i = 0; i < course_ids.size(); ++i) {
		if (course_ids.at(i) == course_id) {
			return;
		}
	}
	course_ids.push_back(course_id);
}

void Student::listCourses() {
	cout << "Courses for " << id << endl;
	for (unsigned int i = 0; i < course_ids.size(); ++i) {
		cout << course_ids.at(i) << endl;
	}
}
