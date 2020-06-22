/* Homework 1
Coinmaker App
Ian Stephenson
CSCE 121-515
*/

/* //// Pseudocode ////

Input dollars and cents and create a value for the total cents
Compute the number of quarters needed by dividing the total number of cents by 25
Update the value of total cents by subtracting the number of quarters multiplied by 25
------ The value returned should be the number of cents that are made up by all the quarters
Update the value of total coins by adding the number of quarters used
--- Repeat this process for the other coins, change the values of the coins

Output all the coins used next to their denominations and output the total number of coins
*/

#include <iostream>
using namespace std;

int main(){
	

	int dollars;
	int cents;
	int dollars_and_cents = 0;
	int num_quarters = 0;
	int num_dimes = 0;
	int num_nickels = 0;
	int num_pennies = 0;
	int total_coins = 0;

	// Input dollars and cents
	
	cout << "Enter dollars: ";
	cin >> dollars;

	cout << "Enter cents: ";
	cin >> cents;
	
	// Compute total number of cents
	
	dollars_and_cents = dollars * 100 + cents;
	
	// Num quarters / 25 will yield integer value of the most possible quarters, that number * 25 will tell how much money will be subtracted from the total cents
	
	num_quarters = dollars_and_cents / 25;
	dollars_and_cents = dollars_and_cents - (num_quarters * 25);
	total_coins += num_quarters;
	
	// The process is the same as above for every different coin but with different numbers
	
	num_dimes = dollars_and_cents / 10;
	dollars_and_cents = dollars_and_cents - (num_dimes * 10);
	total_coins += num_dimes;
	
	num_nickels = dollars_and_cents / 5;
	dollars_and_cents = dollars_and_cents - (num_nickels * 5);
	total_coins += num_nickels;
	
	num_pennies = dollars_and_cents / 1;
	dollars_and_cents = dollars_and_cents - (num_pennies * 1);
	total_coins += num_pennies;
	
	// Output all the values for each coin denomination and total number of coins
	
	cout << "Pennies: " << num_pennies << endl;
	cout << "Nickels: " << num_nickels << endl;
	cout << "Dimes: " << num_dimes << endl;
	cout << "Quarters: " << num_quarters << endl;
	cout << "\nTotal coins used: " << total_coins << endl;
	

}