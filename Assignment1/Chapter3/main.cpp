// Chapter 3 Exercise 18
// Written by Aaron Payne
// This program calculates a savings account total with compound interest2
// Last modification: 01/28/2024
// CLion 2023.3.2 - Modified Run Configuration to Emulate in Terminal
// https://youtrack.jetbrains.com/issue/CPP-17579
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    double  principal, // Principal balance
            rate, // Interest Rate
            amount, // Total Amount in Savings after calculation
            interest; // Interest Rate

    int timesCompounded; // Number of times the interest is compounded

    //NOTE: While running, Clion has a display issue with trailing spaces and tabs in cout, use a workaround from https://youtrack.jetbrains.com/issue/CPP-17579
    // Without a workaround the trailing spaces will instead be in the buffer and display at the beginning of the next cout
    cout << "Enter the principal: ";
    cin >> principal;
    cout << "Enter the interest rate (%): ";
    cin >> rate;
    cout << "Number of times interest is compounded: ";
    cin >> timesCompounded;

    // Convert rate to decimal using compound assignment
    rate /= 100;

    // Calculate the amount now in Savings
    amount = principal * pow((1+rate/timesCompounded),timesCompounded);

    // Separate the Interest
    interest = amount - principal;

    // Convert the rate back to a 'percent' using compound assigment
    rate *= 100;

    // Set up the display
    cout << setprecision(2) << fixed << left << setw(19) << "Interest Rate:" // Precision is set to 2 and fixed so there will always be two decimal places for floats
    << right << setw(10) << rate << "%" << endl
    << left << setw(19) << "Times Compounded: "
    << right << setw(10) << timesCompounded << endl
    << left << setw(20) << "Principal: " << "$"
    << right << setw(8) << principal << endl
    << left << setw(20) << "Interest: " << "$"
    << right << setw(8) << interest << endl
    << left << setw(20) << "Amount in Savings: " << "$"
    << right << setw(8) << amount;

    return 0;
}
