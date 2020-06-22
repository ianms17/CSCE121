#include "functions.h"
#include "provided.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int readPrefs(char fileName[], int ngames, int prefs[]) {
	int rating;
	int gameID;
	int validCount = 0;
	
	ifstream ifs;
	ifs.open(fileName);
	if (!ifs) {
		return -1;
	}
	else {
		while (!ifs.eof()) {
			ifs >> gameID;
			ifs >> rating;
		
			if (gameID > ngames-1 || gameID < 0) {
				continue;
			}
			else if (ifs.good()) {
				prefs[gameID] = rating;
				validCount++;
			}
		}
		return validCount;
	}
}

int readPlan (char fileName[], int ngames, int plan[]) {
	int day;
	int gameID;
	
	ifstream ifs;
	ifs.open(fileName);
	if (!ifs) {
		return -1;
	}
	else {
		while (!ifs.eof()) {
			ifs >> day >> gameID;
			if (ifs.good()) {
				//cout << day << " " << gameID << endl;
				plan[day] = gameID;
			}
		}
		return 0;
	}
	
}

int computeFunLevel (int start, int duration, int prefs[], int ngames, int plan[]) {
	int sum = 0;
	if (start + duration > 365) {
		return -1;
	}
	else {
		for (int i = start; i < start + duration; ++i) {
			sum = sum + prefs[plan[i]];
		}
		return sum;
	}
}

int findBestVacation (int duration,  int prefs[], int ngames, int plan[]) {
	int maxFun = -1;
	int startDate;
	for (int i = 1; i <= 365; ++i) {
		if (computeFunLevel(i, duration, prefs, ngames, plan) > maxFun) {
			maxFun = computeFunLevel(i, duration, prefs, ngames, plan);
			startDate = i;
		}
	}
	return startDate;
}



