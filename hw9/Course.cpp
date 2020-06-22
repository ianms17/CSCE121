#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime) :
		id(id), title(title), startTime(startTime), endTime(endTime) {}
	

string Course::getID() {
	return this->id;
}

string Course::getTitle() {
	return this->title;
}
Date Course::getStartTime() {
	return this->startTime;
}

Date Course::getEndTime() {
	return this->endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar) {
	if (ar.getDate() >= startTime && ar.getDate() <= endTime) {
		attendanceRecords.push_back(ar);
	} else {
		cout << "did not save this record." << endl;
	}
}

void Course::outputAttendance() {
	for (unsigned int i = 0; i < attendanceRecords.size(); ++i) {
		cout << attendanceRecords.at(i).getDate().getMonth() << '/';
		cout << attendanceRecords.at(i).getDate().getDay() << '/';
		cout << attendanceRecords.at(i).getDate().getYear() << ' ';
		cout << setfill('0') << setw(2) << attendanceRecords.at(i).getDate().getHour() << ':';
		cout << setfill('0') << setw(2) << attendanceRecords.at(i).getDate().getMin() << ':';
		cout << setfill('0') << setw(2) << attendanceRecords.at(i).getDate().getSec() << ',';
		cout << attendanceRecords.at(i).getCourseID() << ',';
		cout << attendanceRecords.at(i).getStudentID() << endl;
	}
}

void Course::outputAttendance(std::string student_id) {
	unsigned int problematicIf = 0;
	for (unsigned int i = 0; i < attendanceRecords.size(); ++i) { 
		if (attendanceRecords.at(i).getStudentID() == student_id) {
			problematicIf += 1;
			cout << attendanceRecords.at(i).getDate().getMonth() << '/';
			cout << attendanceRecords.at(i).getDate().getDay() << '/';
			cout << attendanceRecords.at(i).getDate().getYear() << ' ';
			cout << setfill('0') << setw(2) << attendanceRecords.at(i).getDate().getHour() << ':';
			cout << setfill('0') << setw(2) << attendanceRecords.at(i).getDate().getMin() << ':';
			cout << setfill('0') << setw(2) << attendanceRecords.at(i).getDate().getSec() << ',';
			cout << attendanceRecords.at(i).getCourseID() << ',';
			cout << attendanceRecords.at(i).getStudentID() << endl;
		}	
	}
	if (problematicIf == 0) {
		cout << "No Records" << endl;
	}
}
