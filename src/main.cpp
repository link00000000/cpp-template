#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

double newBalance(double, double);
double newBalance(double, double, int);
int yearsNeeded(double, double, double);

int main()
{
    // Set formatting to display decimals
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);

    // Keeps the validation loop running until a valid input is provided
    bool isInvalidInput = true;
    double initDeposit = 0.0;
    do
    {
        // Ask the user for initial deposit
        std::cout << "Initial Deposit: ";
        std::cin >> initDeposit;

        // Check validity of input
        if(std::cin.fail() || initDeposit < 0)
        {
            std::cout << "You must enter a valid positive value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            isInvalidInput = false;
        }
    }
    while(isInvalidInput);


    isInvalidInput = true;
    double rate = 0.0;
    do
    {
        // Ask the user for interest rate
        std::cout << "Interest Rate: ";
        std::cin >> rate;

        // Check validity of input
        if(std::cin.fail())
        {
            std::cout << "Interest rate must be a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            isInvalidInput = false;
        }
    }
    while(isInvalidInput);

    // Print balance after 1 year
    std::cout << "Balance after 1 year:\t" << newBalance(initDeposit, rate) << std::endl;

    // Print balance after 10 years compound
    std::cout << "Balance after 10 years:\t" << newBalance(initDeposit, rate, 10) << std::endl;

    // Print num of years until balance is 1 million
    std::cout << "Years until $1 million:\t" << yearsNeeded(initDeposit, rate, 1000000) << std::endl;

    return 0;
}

// Computes the balance after 1 year
double newBalance(double init, double interest)
{
    return newBalance(init, interest, 1);
}

// Computes the balance after n years
double newBalance(double init, double interest, int years)
{
    return init * std::pow(1 + interest, years);
}

// Computes the number of years until the account reaches 1 million
int yearsNeeded(double init, double interest, double finalAmnt)
{
    return std::log(finalAmnt / init) / std::log(1 + interest);
}
