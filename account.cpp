#include "account.h"

Account::Account(double init_balance)
    : balance(init_balance)
{
}

void Account::setBalance(double b)
{
    if (b >= 0.0)
    {
        balance = b;
    }
}

double Account::getBalance() const
{
    return balance;
}

bool Account::deposit(double amount)
{
    if (amount <= 0.0)
    {
        return false;
    }

    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (amount <= 0.0 || amount > balance)
    {
        return false;
    }

    balance -= amount;
    return true;
}

SavingsAccount::SavingsAccount(double init_balance, float rate)
    : Account(init_balance), interestRate(rate)
{
}

double SavingsAccount::calcInterest() const
{
    return balance * interestRate;
}

ChequingAccount::ChequingAccount(double init_balance, double fee)
    : Account(init_balance), transactionFee(fee)
{
}

bool ChequingAccount::withdraw(double amount)
{
    if (amount <= 0.0)
    {
        return false;
    }

    const double total = amount + transactionFee;
    if (total > balance)
    {
        return false;
    }

    balance -= total;
    return true;
}