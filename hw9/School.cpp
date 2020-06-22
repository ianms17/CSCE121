#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addCourses(string filename) {
	ifstream ifs(filename);
	if (!ifs.is_open()) {
		cout << "Unable to open file: " << filename << endl;
		return;
	}
	while(!ifs.eof()) {
		string line;
		string sectionNum;
		string start_time;
		string end_time;
		string course_name;
		string start_hour;
		string start_minute;
		string end_hour;
		string end_minute;
		
		getline(ifs, line);
		istringstream ss(line);
		getline(ss, sectionNum, ',');
		getline(ss, start_hour, ':');
		getline(ss, start_minute, ',');
		getline(ss, end_hour, ':');
		getline(ss, end_minute, ',');
		getline(ss, course_name);
		
		int start_hour_int = 0;
		int start_minute_int = 0;
		int end_hour_int = 0;
		int end_minute_int = 0;
		
		istringstream shrINT(start_hour);
		shrINT >> start_hour_int;
		istringstream sminINT(start_minute);
		sminINT >> start_minute_int;
		istringstream ehrINT(end_hour);
		ehrINT >> end_hour_int;
		istringstream eminINT(end_minute);
		eminINT >> end_minute_int;
		
		Date startTime = Date(start_hour_int, start_minute_int, 0);
		Date endTime = Date(end_hour_int, end_minute_int, 0);
		
		if (!ss.fail()) {
			courses.push_back(Course(sectionNum, course_name, startTime, endTime));
		}
	}
}

void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
	if (!ss.fail()) {
		students.push_back(Student(uin, name));
    }
  }
}

void School::addAttendanceData(std::string filename) {
	ifstream ss(filename);
	if (!ss.is_open()) {
		cout << "Unable to open file: " << filename << endl;
		return;
	}
	while (!ss.eof()) {
		string line;
		string year;
		string month;
		string day;
		string hour;
		string minute;
		string second;
		string sectionNumber;
		string uin;
		getline(ss, line);
		istringstream ifs(line);
		getline(ifs, year, '-');
		getline(ifs, month, '-');
		getline(ifs, day, ' ');
		getline(ifs, hour, ':');
		getline(ifs, minute, ':');
		getline(ifs, second, ',');
		getline(ifs, sectionNumber, ',');
		getline(ifs, uin);
		
		int hourInt = 0;
		int minuteInt = 0;
		int secondInt = 0;
		int year_int = 0;
		int month_int = 0;
		int day_int = 0;
		
		istringstream hrINT(hour);
		hrINT >> hourInt;
		
		istringstream minINT(minute);
		minINT >> minuteInt;
		
		istringstream secINT(second);
		secINT >> secondInt;
		
		istringstream yearINT(year);
		yearINT >> year_int;
		
		istringstream monthINT(month);
		monthINT >> month_int;
		
		istringstream dayINT(day);
		dayINT >> day_int;
		
		Date arrivalTime = Date(year_int, month_int, day_int, hourInt, minuteInt, secondInt);
		
		for (unsigned int i = 0; i < this->courses.size(); ++i) {
			if (this->courses.at(i).getID() == sectionNumber) { 	
				if (!ifs.fail()) {
					this->courses.at(i).addAttendanceRecord(AttendanceRecord(sectionNumber, uin, arrivalTime));
				}
			}
		}
	}		
}

void School::listCourses() {
	int courseSize = courses.size();
	if (courseSize == 0) {
		cout << "No Courses" << endl;
	} else if (courseSize > 0) {
		for (unsigned int i = 0; i < courseSize; ++i) {
			cout << this->courses.at(i).getID() << ',';
			cout << setfill('0') << setw(2) << this->courses.at(i).getStartTime().getHour() << ':' << setfill('0') << setw(2) << this->courses.at(i).getStartTime().getMin();
			cout << ',' << setfill('0') << setw(2) << this->courses.at(i).getEndTime().getHour() << ':' << setfill('0') << setw(2) << this->courses.at(i).getEndTime().getMin() << ',';
			cout << this->courses.at(i).getTitle() << endl;
			cout << endl;
		}
	}
}

void School::listStudents() {
	int studentSize = students.size();
	if (studentSize == 0) {
		cout << "No Students" << endl;
	} else if (studentSize > 0) {
		for (unsigned int i = 0; i < studentSize; ++i) {
			cout << students.at(i).get_id() << ',' << students.at(i).get_name() << endl;
		}
	}
}

void School::outputCourseAttendance(std::string course_id) {
	for (unsigned int i = 0; i < courses.size(); ++i) {
		if (courses.at(i).getID() == course_id) {
			courses.at(i).outputAttendance();
		}
	}
}

void School::outputStudentAttendance(std::string student_id, std::string course_id) {
	for (unsigned int i = 0; i < courses.size(); ++i) {
		if (courses.at(i).getID() == course_id) {
			courses.at(i).outputAttendance(student_id);
		}
	}
}


