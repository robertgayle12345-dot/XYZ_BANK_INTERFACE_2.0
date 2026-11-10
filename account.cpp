
#include "account.h"
#include <iostream>
using namespace std;

// ==========================================
// SECTION 1: ACCOUNT BASE CLASS
// ==========================================

// Constructor
Account::Account(double initialBalance)
{
    if (initialBalance >= 0.00)
    {
        balance = initialBalance;
    }
    else
    {
        balance = 0.00;
    }
}

// Set Account Balance
void Account::setBalance(double b)
{
    if (b >= 0.00)
    {
        balance = b;
    }
}

// Get Account Balance
double Account::getBalance() const
{
    return balance;
}

// Deposit Money
bool Account::deposit(double amount)
{
    if (amount > 0.00)
    {
        balance += amount;
        cout << "Deposit Successful!" << endl;
        return true;
    }
    else
    {
        cout << "Invalid deposit amount!" << endl;
        return false;
    }
}

// Withdraw Money
bool Account::withdraw(double amount)
{
    if (amount > 0.00 && amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal Successful!" << endl;
        return true;
    }
    else
    {
        cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        return false;
    }
}

// ==========================================
// SECTION 2: SAVINGS ACCOUNT CLASS
// ==========================================

// Savings Account Constructor
SavingsAccount::SavingsAccount(double init_balance, float rate)
    : Account(init_balance)
{
    interestRate = rate;
}

// Calculate Interest
double SavingsAccount::calcInterest() const
{
    return balance * interestRate;
}

// ==========================================
// SECTION 3: CHEQUING ACCOUNT CLASS
// ==========================================

// Chequing Account Constructor
ChequingAccount::ChequingAccount(double init_balance, double fee)
    : Account(init_balance)
{
    transactionFee = fee;
}

// Withdraw Money Including Transaction Fee
bool ChequingAccount::withdraw(double amount)
{
    double totalAmount = amount + transactionFee;

    if (amount > 0.00 && totalAmount <= balance)
    {
        balance -= totalAmount;

        cout << "Withdrawal Successful!" << endl;
        cout << "Transaction Fee: $" << transactionFee << endl;

        return true;
    }
    else
    {
        cout << "Withdrawal Failed!" << endl;
        cout << "Insufficient funds or invalid withdrawal amount." << endl;

        return false;
    }
}
