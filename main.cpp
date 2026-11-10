
#include <iostream>
#include <iomanip>
#include <limits>
#include "account.h"

using namespace std;

// ==========================================
// DISPLAY ATM MENU
// ==========================================

void displayMenu()
{
    cout << "\n============================================\n";
    cout << "             XYZ BANK ATM SYSTEM            \n";
    cout << "============================================\n";
    cout << " 1. Check Account Balance\n";
    cout << " 2. Deposit Money\n";
    cout << " 3. Withdraw Money (Chequing applies fee)\n";
    cout << " 4. Calculate & Apply Interest (Savings)\n";
    cout << " 5. Exit Program\n";
    cout << "============================================\n";
    cout << "Select your transaction type (1-5): ";
}

// ==========================================
// PAUSE PROGRAM
// ==========================================

void pauseAndContinue()
{
    cout << "\nPress Enter to return to main menu...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ==========================================
// MAIN PROGRAM
// ==========================================

int main()
{
    cout << fixed << setprecision(2);

    // Welcome Banner
    cout << "============================================\n";
    cout << "          WELCOME TO XYZ BANK SYSTEM        \n";
    cout << "       Object-Oriented Inheritance ATM      \n";
    cout << "============================================\n\n";

    // Create Account Objects
    SavingsAccount mySavings(2500.00, 0.05);

    ChequingAccount myChequing(1500.00, 2.50);

    int choice;
    int accountType;
    double amount;

    // ATM Menu Loop
    while (true)
    {
        displayMenu();

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (choice == 5)
        {
            cout << "\nThank you for banking with XYZ Bank.\n";
            cout << "Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5)
        {
            cout << "\nInvalid menu selection.\n";
            pauseAndContinue();
            continue;
        }

        // Select Account Type
        if (choice >= 1 && choice <= 3)
        {
            cout << "\nSelect Account Type:\n";
            cout << "1. Savings Account\n";
            cout << "2. Chequing Account\n";
            cout << "Enter choice (1-2): ";

            if (!(cin >> accountType))
            {
                cout << "Invalid account selection.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            if (accountType != 1 && accountType != 2)
            {
                cout << "Invalid account type selected.\n";
                pauseAndContinue();
                continue;
            }
        }

        switch (choice)
        {
            // ==================================
            // OPTION 1: CHECK BALANCE
            // ==================================

            case 1:

                if (accountType == 1)
                {
                    cout << "\nSavings Account Balance: $"
                         << mySavings.getBalance() << endl;
                }
                else
                {
                    cout << "\nChequing Account Balance: $"
                         << myChequing.getBalance() << endl;
                }

                pauseAndContinue();
                break;

            // ==================================
            // OPTION 2: DEPOSIT MONEY
            // ==================================

            case 2:

                cout << "\nEnter amount to deposit: $";

                if (!(cin >> amount))
                {
                    cout << "Invalid amount entered.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    pauseAndContinue();
                    break;
                }

                if (accountType == 1)
                {
                    mySavings.deposit(amount);

                    cout << "Updated Savings Balance: $"
                         << mySavings.getBalance() << endl;
                }
                else
                {
                    myChequing.deposit(amount);

                    cout << "Updated Chequing Balance: $"
                         << myChequing.getBalance() << endl;
                }

                pauseAndContinue();
                break;

            // ==================================
            // OPTION 3: WITHDRAW MONEY
            // ==================================

            case 3:

                cout << "\nEnter amount to withdraw: $";

                if (!(cin >> amount))
                {
                    cout << "Invalid amount entered.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    pauseAndContinue();
                    break;
                }

                if (accountType == 1)
                {
                    mySavings.withdraw(amount);

                    cout << "Updated Savings Balance: $"
                         << mySavings.getBalance() << endl;
                }
                else
                {
                    myChequing.withdraw(amount);

                    cout << "Updated Chequing Balance: $"
                         << myChequing.getBalance() << endl;
                }

                pauseAndContinue();
                break;

            // ==================================
            // OPTION 4: CALCULATE INTEREST
            // ==================================

            case 4:
            {
                cout << "\n--- SAVINGS ACCOUNT INTEREST ---\n";

                double interest = mySavings.calcInterest();

                cout << "Interest Earned: $"
                     << interest << endl;

                mySavings.deposit(interest);

                cout << "New Savings Balance: $"
                     << mySavings.getBalance() << endl;

                pauseAndContinue();
                break;
            }

            default:

                cout << "Invalid selection.\n";
                pauseAndContinue();
        }
    }

    return 0;
}
