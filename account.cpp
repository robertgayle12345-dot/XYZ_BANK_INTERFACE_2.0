#include "account.h"
using namespace std;

//Constructor
Account::Account(double initialBalance)
{
    if (initialBalance>=0.00)
    {
        balance=initialBalance;
    }
else
{
    balance = 0.00;
}
}

//Account Balance
double Account::getBalance () const
{
    return balance;
}

//Deposit Money
void Account::credit(double amount)
{
    if(amount > 0)
    {
    balance += amount;
    cout << "Deposit Successful" << endl;
    }
}

//Withdraw Money
bool Account::debit(double amount)
{
    if(amount >0 && amount <=balance)
    {
        balance -= amount;
        cout << "Withdrawal Successful" << endl;
        return true;
    }
    else
    {
        cout << "Invalid withdrawal amount or insufficient funds" << endl;
        return false;
    }
}
