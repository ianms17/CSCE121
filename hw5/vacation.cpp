#include "functions.h"
#include "provided.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main () {
	int ngames;
	int duration;
	char game_titles[255];
	char preferences[255];
	char plan_file[255];
	char gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE];
	int prefs[200];
	for (int i = 0; i < 200; ++i) {
		prefs[i] = 0;
	}
	int plan[366];
	
	cout << "Please enter ngames and duration: ";
	cin >> ngames;
	cin >> duration;
	
	if (ngames > 200 || duration < 0 || duration > 365) {
		cout << "Invalid input." << endl;
	}
	else {
		cout << "Please enter name of file with titles: ";
		cin >> game_titles;
		cout << "Please enter name of file with preferences: ";
		cin >> preferences;
		cout << "Please enter name of file with plan: ";
		cin >> plan_file;
	
		//readPrefs(preferences, ngames, prefs);
		//readPlan(plan_file, ngames, plan);
		//readGameTitles(game_titles, ngames, gameTitles);
		int prefsReturn = readPrefs(preferences, ngames, prefs);
		int planReturn = readPlan(plan_file, ngames, plan);
		int gamesReturn = readGameTitles(game_titles, ngames, gameTitles);
		if (prefsReturn == -1 || planReturn == -1 || gamesReturn == -1) {
			
			cout << "Invalid file." << endl;
		}
		else {
			int bestVacation = findBestVacation(duration, prefs, ngames, plan);
			cout << "Best start day is " << bestVacation << endl;
			cout << "Games to be played: " << endl;
			printGamesPlayedInVacation(bestVacation, duration, plan, gameTitles, ngames);
			return 0;
		}
	}
}
