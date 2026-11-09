#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
    double balance;

public:
    explicit Account(double initialBalance = 0.0);
    virtual ~Account() = default;

    void setBalance(double b);
    double getBalance() const;

    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
};

class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount(double init_balance, float rate);
    double calcInterest() const;
};

class ChequingAccount : public Account
{
private:
    double transactionFee;

public:
    ChequingAccount(double init_balance, double fee);
    bool withdraw(double amount) override;
};

#endif