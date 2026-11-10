
#ifndef ACCOUNT_H
#define ACCOUNT_H

// ==========================================
// BASE CLASS: ACCOUNT
// ==========================================

class Account
{
protected:

    double balance;

public:

    // Constructor
    explicit Account(double initialBalance = 0.0);

    // Virtual Destructor
    virtual ~Account() = default;

    // Set and Get Balance
    void setBalance(double b);

    double getBalance() const;

    // Deposit and Withdraw Functions
    virtual bool deposit(double amount);

    virtual bool withdraw(double amount);
};

// ==========================================
// DERIVED CLASS: SAVINGS ACCOUNT
// ==========================================

class SavingsAccount : public Account
{
private:

    float interestRate;

public:

    // Constructor
    SavingsAccount(double init_balance, float rate);

    // Calculate Interest
    double calcInterest() const;
};

// ==========================================
// DERIVED CLASS: CHEQUING ACCOUNT
// ==========================================

class ChequingAccount : public Account
{
private:

    double transactionFee;

public:

    // Constructor
    ChequingAccount(double init_balance, double fee);

    // Withdraw Including Transaction Fee
    bool withdraw(double amount) override;
};

#endif
