#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	int a;
	int b;
	cin >> a;
	cin >> b;
	int repeatCounter = 0;
	int totalCounter = 0;
	cout << "Enter numbers a <= b: ";
	
	
	if (a > b) {									// a must be greater than b
		cout << "Invalid input" << endl;
	} else if (a > 10000 || b > 10000) {			// numbers must be between 0 and 10000
		cout << "Invalid input" << endl;
	} else if (a < 0 || b < 0) {					// numbers cannot be negative
		cout << "Invalid input" << endl;
	} else {
		// iterate through the addresses in the range given
		for (int givenAddress = a; givenAddress <= b; ++givenAddress) {
			// iterate through the digits 1-9 to check how many times each occurs
			for (int digit = 0; digit <= 9; ++digit) {							
				// function call to check the digit occurences in each address					
				if (countDigitOccurrences(givenAddress, digit)> 1) {				
					// if there is a repeat, add to the repeat counter
					repeatCounter += 1;
					break;
				}
			}	
		} 
		// Number of total addresses minus number of repeat of addresses
		int validAddress = (b - a) - repeatCounter + 1;
		// returns number of valid addresses
		cout << "There are " << validAddress << " valid numbers between " << a << " and " << b << endl;
	return 0;
	}
}