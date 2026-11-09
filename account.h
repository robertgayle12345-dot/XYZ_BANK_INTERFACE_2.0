#ifndef ACCOUNT_H //file gaurds that prevents the compiler from
#define ACCOUNT_H //running the same file more than once

#include <iostream>
using namespace std;


//Base/Parent Account Class
class Account
{
    protected://PROTECTED ALLOWS DATA ACCESS FOR DERIVED CLASSES
        double balance;


    public:
        Account(double initialBalance); //Constructor: takes the starting
        virtual ~Account() {} //cleans up leaks if a derived object is deleted

            void setBalance(double b); //reads balance
            void getBalance() const; //ensure balances cant be tampered with

            virtual bool deposit(double amount); //allows the derived clases to act and make changes to initial value
            virtual bool withdraw(double amount); //same as above
        }
// Derived Class: SavingsAccount
    class SavingsAccount :: public Account //inherits everything from protected 'Account'
            {
        private:
        float interestRate;

        public:
            SavingsAccount(double init_balance, float rate);
            double calcInterest() const;//used to track interest weight
        };

// Derived Class: ChequingAccount
    class ChequingAccount : public Account //inherits everything from protected 'Account'
    {
        private:
        double transactionFee;

        public:
            ChequingAccount(double init_balance, double fee);
            bool withdraw(double amount) override; //enforcing deductio rule during withdrawls
};

#endif // ACCOUNT_H