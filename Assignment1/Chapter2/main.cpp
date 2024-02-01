// Chapter 2 Exercise 17
// Written by Aaron Payne
// This program calculates stock commission
// Last modification: 01/28/2024
// Written using Qt Creator 12.0.1 (Community)
#include <iostream>

using namespace std;

int main()
{
    int     sharesBought = 750; // Number of shares purchase
    double  pricePerShare = 35.00, // Price per Share
            commission = 0.02, // Percent commission per transaction
            stockTotal, // Amount paid for Stock alone
            commissionTotal, // Amount of the commission
            sumTotal; // Total of stock and commission

    // Calculate the total stock price
    stockTotal = sharesBought * pricePerShare;

    // Calculate the commission on this transaction
    commissionTotal = stockTotal * commission;

    // Add the stock price and commission together to get the final total
    sumTotal = stockTotal + commissionTotal;

    // Console Output Stream
    cout << "Amount Paid for the stock alone: $"
         << stockTotal << endl
         << "Amount of the commission: $"
         << commissionTotal << endl
         << "Total amount paid: $"
         << sumTotal << endl;

    return 0;
}
