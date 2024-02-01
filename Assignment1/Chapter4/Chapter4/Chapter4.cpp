// Chapter 4 Exercise 10
// Written by Aaron Payne
// This program calculates the number of days of a give month and year
// Last modification: 01/28/2024
// Microsoft Visual Studio Community 2022 (64-bit) Version 17.8.5 - CMake Project


#include "Chapter4.h" 
#include <iostream>

using namespace std;

int main()
{

	int month, // Month
		year, // Needed for february
		days; // Number of days in the month

	// Ask for month. We do not need to ask for year unless it's February.
	cout << "Enter a month (1-12): ";
	cin >> month;

	// Check which month was entered, Fall through for months with the same number of days
	switch (month) {

		//Months with 31 Days
		case 1: // January
		case 3: // March
		case 5: // May
		case 7: // July
		case 8: // August
		case 10: // October
		case 12: // December
		days = 31;
		break;

		// Months with 30 days
		case 4: // April
		case 6: // June
		case 9: // September
		case 11: // November
		days = 30;
		break;

		case 2: // February

			// Ask for the year
			cout << "Enter a year: ";
			cin >> year;

			// Determine if it's a leap year
			if (year % 100) // Remainder, value is true and it's not divisible by 100
			{
				if (year % 4) // Leap year only if divisible by 4
					days = 29;
				else
					days = 28;
			}
			else // No remainder, value is false and it is divisible by 100
			{
				if (year % 400)
					days = 28;
				else // Leap year only if divisible by 400
					days = 29;
			}
		break;

		default: // Something other than 1-12 was entered.
		cout << "Please enter a valid month (1-12). Try again!";
		return 0; // Exit here so we don't call 'days' without initializing it.
	}

	cout << days << " Days";

	return 0;
}
