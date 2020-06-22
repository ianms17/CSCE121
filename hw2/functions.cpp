#include <iostream>
#include "functions.h"

int countDigitOccurrences (int n, int digit) {
	int lastDigit = 0;
	int occurenceCounter = 0;
	while (n > 0) {
		lastDigit = n % 10;					// Retrieve number at end of address
		if (lastDigit == digit) {
			occurenceCounter += 1;			// Counts how many times the number occurs in the address
		}
		n = n / 10;							// Remove last number from address
	}
	return occurenceCounter;
}