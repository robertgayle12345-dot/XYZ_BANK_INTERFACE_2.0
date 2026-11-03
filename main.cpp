#include <iostream>
using namespace std;

//Account Class
class Account
{
    private:
        double balance; //PRIVATE DATA FOR MEMBER ACC BALANCE

        //Constructor: initializes balance to 1000.0 or to 0.0 if the initial balance is invalid
    public:
        Account(double initialBalance)
        {
            if (initialBalance>=1000.00)
            {
                balance = initialBalance;
            }
            else
            {
                balance=0.00;
                cout<<"[WARNING] Initial balance was invalid (must be at least $1000.00 or more). Balance set to $0.00.\n";
            }}

// Deposit function: adds amount to current balance
        void deposit(double amount)
        {
            if (amount <= 0)
            {
                cout << "INVALID DEPOSIT AMOUNT. PLEASE ENTER A POSITIVE VALUE.\n";
                return;
            }
            balance = balance +  amount;
            cout << "AMOUNT DEPOSITED SUCCESSFULLY $" << amount << "\n";
            cout << "BALANCE: $" << balance << "\n";
        }
// Withdraw function: debits money and checks against balance
        void withdraw(double amount)
        {
            if (amount <= balance)
            {
                balance = balance - amount;
                cout << " WITHDRAW SUCCESSFULL $" << amount << "\n";
                cout << "BALANCE: $" << balance << "\n"; // DISPLAY ACC BALANCE
            }
            else
            {
                cout << "DEBIT AMOUNT EXCEED ACCOUNT BALANCE.\n";
            }
        }

        double getBalance() const
        {
            return balance;
        }
};

void displayMenu()
{
    cout << "\n============================================\n";
    cout << "           XYZ BANK ATM SYSTEM              \n";
    cout << "============================================\n";
    cout << " 1. ACCOUNT BALANCE\n";
    cout << " 2. ACCOUNT DEPOSIT\n";
    cout << " 3. ACCOUNT WITHDRAW\n";
    cout << " 4. EXIT\n";
    cout << "============================================\n";
    cout << "SELECT YOUR TRANSACTION TYPE (1-4): ";
}

void pauseAndContinue()
{
    cout << "\nPLEASE CLICK ENTER TO RETURN TO MAIN MENUE...";
    cin.ignore(10000, '\n');
    cin.get();
}

int main()
{
        // 1. Display Welcome Banner First
    cout << "============================================\n";
    cout << "         WELCOME TO XYZ BANK SYSTEM         \n";
    cout << "           XYZ BANK ATM INTERFACE           \n";
    cout << "============================================\n\n";

    Account myAccount(2000.0); // Create an account with an initial balance of 1000.0
    cout << "[System] YOUR ACCOUNT BALANCE IS: $" << myAccount.getBalance() << "\n";

    cout << "\n       PRESS ENTER TO CONTINUE...";
    cin.get();

    int choice;
    double amount;

    // 3. Interactive ATM Menu Loop
    while (true)
    {
        displayMenu();

    if (!(cin >> choice))
        {
            cout << "INVALID PLEASE ENTER  1-4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Switch statement to handle user selections
        switch (choice)
        {
            case 1:
                cout << "\nACCONT BALANCE: $" << myAccount.getBalance() << "\n";
                pauseAndContinue();
                break;

            case 2:
                cout << "ACCONT DEPOSIT: $";
                cin >> amount;
                myAccount.deposit(amount);
                pauseAndContinue();
                break;

            case 3:
                cout << "ACCONT WIDTHRAW: $";
                cin >> amount;
                myAccount.withdraw(amount);
                pauseAndContinue();
                break;

            case 4:
                cout << "THANK YOU XYZ Bank.!\n";
                return 0; // Exits the program

            default:
                cout << "INVALID PLEASE ENTER CHOICE 1-4.\n";
        }
    }

    return 0;
}