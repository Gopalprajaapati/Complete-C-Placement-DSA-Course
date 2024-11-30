#include <iostream>
#include <cmath> // For pow function
using namespace std;

int main()
{
    // Declare variables as double for accuracy
    double principal, rate, time, totalAmount, compoundInterest;

    // Input principal amount
    cout << "Enter the principal amount: ";
    cin >> principal;

    // Input rate of interest
    cout << "Enter the annual interest rate (in percentage): ";
    cin >> rate;

    // Input time in years
    cout << "Enter the time (in years): ";
    cin >> time;

    // Calculate total amount
    totalAmount = principal * pow((1 + rate / 100), time);

    // Calculate compound interest
    compoundInterest = totalAmount - principal;

    // Display results
    cout << "Compound Interest: " << compoundInterest << endl;
    cout << "Total Amount (Principal + Interest): " << totalAmount << endl;

    return 0;
}
