#include <iostream>
#include "account.h"

using namespace std;

// Function to display the interactive ATM Menu
void displayMenu()
{
    cout << "\n============================================\n";
    cout << "           XYZ BANK ATM SYSTEM              \n";
    cout << "============================================\n";
    cout << " 1. Check Account Balance\n";
    cout << " 2. Deposit Money\n";
    cout << " 3. Withdraw Money (Chequing applies fee)\n";
    cout << " 4. Calculate & Apply Interest (Savings)\n";
    cout << " 5. Exit Program\n";
    cout << "============================================\n";
    cout << "Select your transaction type (1-5): ";
}

void pauseAndContinue()
{
    cout << "\nPress Enter to return to main menu...";
    cin.ignore(10000, '\n');
    cin.get();
}

int main()
{
    // Display Welcome Banner
    cout << "============================================\n";
    cout << "         WELCOME TO XYZ BANK SYSTEM         \n";
    cout << "      Object-Oriented Inheritance ATM       \n";
    cout << "============================================\n\n";

    // Initialize accounts with starting balances and rates/fees
    SavingsAccount mySavings(2500.0, 0.05);   // $2500.00 initial balance, 5% interest rate (0.05)
    ChequingAccount myChequing(1500.0, 2.50); // $1500.00 initial balance, $2.50 transaction fee

    int choice, accountType = 1;
    double amount;

    // Interactive ATM Menu Loop
    while (true)
    {
        displayMenu();

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 5)
        {
            cout << "Thank you for banking with XYZ Bank. Goodbye!\n";
            break;
        }

        // For options 1 through 3, ask which account type the user wants to use
        if (choice >= 1 && choice <= 3)
        {
            cout << "\nSelect Account Type:\n";
            cout << " 1. Savings Account\n";
            cout << " 2. Chequing Account\n";
            cout << "Enter choice (1-2): ";
            cin >> accountType;

            if (accountType != 1 && accountType != 2)
            {
                cout << "Invalid account type selected.\n";
                pauseAndContinue();
                continue;
            }
        }

        switch (choice)
        {
            case 1: // Check Balance
                if (accountType == 1)
                {
                    cout << "\nSavings Account Balance: $" << mySavings.getBalance() << "\n";
                }
                else
                {
                    cout << "\nChequing Account Balance: $" << myChequing.getBalance() << "\n";
                }
                pauseAndContinue();
                break;

            case 2: // Deposit Money
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (accountType == 1)
                {
                    mySavings.deposit(amount);
                    cout << "Updated Savings Balance: $" << mySavings.getBalance() << "\n";
                }
                else
                {
                    myChequing.deposit(amount);
                    cout << "Updated Chequing Balance: $" << myChequing.getBalance() << "\n";
                }
                pauseAndContinue();
                break;

            case 3: // Withdraw Money
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (accountType == 1)
                {
                    mySavings.withdraw(amount);
                    cout << "Updated Savings Balance: $" << mySavings.getBalance() << "\n";
                }
                else
                {
                    myChequing.withdraw(amount); // Automatically subtracts transaction fee if successful!
                    cout << "Updated Chequing Balance: $" << myChequing.getBalance() << "\n";
                }
                pauseAndContinue();
                break;

            case 4: // Calculate & Apply Interest (Savings Account feature)
            {
                cout << "\n--- Savings Account Interest Calculation ---\n";
                double interest = mySavings.calcInterest();
                cout << "Interest Earned (balance * rate): $" << interest << "\n";
                mySavings.deposit(interest);
                cout << "New Savings Balance After Interest: $" << mySavings.getBalance() << "\n";
                pauseAndContinue();
                break;
            }

            default:
                cout << "Invalid choice. Please select an option between 1 and 5.\n";
                pauseAndContinue();
        }
    }

    return 0;
}