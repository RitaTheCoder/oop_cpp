#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    int accountNumber;
    string customerName;
    double balance;
    string history[100];
    int transactionCount;

public:
    Account()
    {
        accountNumber = 0;
        customerName = "";
        balance = 0;
        transactionCount = 0;
    }

    void openAccount(int accNo, string name, double amount)
    {
        accountNumber = accNo;
        customerName = name;
        balance = amount;

        history[transactionCount++] =
            "Account Opened with Balance: " + to_string(amount);
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    string getCustomerName()
    {
        return customerName;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        history[transactionCount++] =
            "Deposited: " + to_string(amount);
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
            return false;

        balance -= amount;
        history[transactionCount++] =
            "Withdraw: " + to_string(amount);
        return true;
    }

    void addHistory(string text)
    {
        history[transactionCount++] = text;
    }

    void showAccount()
    {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : " << balance << endl;
    }

    void showHistory()
    {
        cout << "\nTransaction History (" << customerName << ")\n";

        if (transactionCount == 0)
        {
            cout << "No Transactions.\n";
            return;
        }

        for (int i = 0; i < transactionCount; i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
};

class Bank
{
private:
    Account accounts[100];
    int totalAccounts;

public:
    Bank()
    {
        totalAccounts = 0;
    }

    int searchAccount(int accNo)
    {
        for (int i = 0; i < totalAccounts; i++)
        {
            if (accounts[i].getAccountNumber() == accNo)
                return i;
        }
        return -1;
    }

    void openAccount()
    {
        int accNo;
        string name;
        double amount;

        cout << "Account Number: ";
        cin >> accNo;

        cout << "Customer Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Initial Deposit: ";
        cin >> amount;

        accounts[totalAccounts].openAccount(accNo, name, amount);
        totalAccounts++;

        cout << "Account Created Successfully.\n";
    }

    void deposit()
    {
        int accNo;
        double amount;

        cout << "Account Number: ";
        cin >> accNo;

        int index = searchAccount(accNo);

        if (index == -1)
        {
            cout << "Account Not Found.\n";
            return;
        }

        cout << "Deposit Amount: ";
        cin >> amount;

        accounts[index].deposit(amount);

        cout << "Deposit Successful.\n";
    }

    void withdraw()
    {
        int accNo;
        double amount;

        cout << "Account Number: ";
        cin >> accNo;

        int index = searchAccount(accNo);

        if (index == -1)
        {
            cout << "Account Not Found.\n";
            return;
        }

        cout << "Withdraw Amount: ";
        cin >> amount;

        if (accounts[index].withdraw(amount))
            cout << "Withdrawal Successful.\n";
        else
            cout << "Insufficient Balance.\n";
    }

    void transfer()
    {
        int fromAcc, toAcc;
        double amount;

        cout << "Sender Account: ";
        cin >> fromAcc;

        cout << "Receiver Account: ";
        cin >> toAcc;

        cout << "Amount: ";
        cin >> amount;

        int sender = searchAccount(fromAcc);
        int receiver = searchAccount(toAcc);

        if (sender == -1 || receiver == -1)
        {
            cout << "Account Not Found.\n";
            return;
        }

        if (!accounts[sender].withdraw(amount))
        {
            cout << "Insufficient Balance.\n";
            return;
        }

        accounts[receiver].deposit(amount);

        accounts[sender].addHistory(
            "Transferred " + to_string(amount) +
            " to Account " + to_string(toAcc));

        accounts[receiver].addHistory(
            "Received " + to_string(amount) +
            " from Account " + to_string(fromAcc));

        cout << "Transfer Successful.\n";
    }

    void transactionHistory()
    {
        int accNo;

        cout << "Account Number: ";
        cin >> accNo;

        int index = searchAccount(accNo);

        if (index == -1)
        {
            cout << "Account Not Found.\n";
            return;
        }

        accounts[index].showHistory();
    }

    void richestCustomer()
    {
        if (totalAccounts == 0)
        {
            cout << "No Accounts Available.\n";
            return;
        }

        int richest = 0;

        for (int i = 1; i < totalAccounts; i++)
        {
            if (accounts[i].getBalance() >
                accounts[richest].getBalance())
                richest = i;
        }

        cout << "\nRichest Customer\n";
        accounts[richest].showAccount();
    }

    void displayAllAccounts()
    {
        if (totalAccounts == 0)
        {
            cout << "No Accounts Available.\n";
            return;
        }

        for (int i = 0; i < totalAccounts; i++)
        {
            accounts[i].showAccount();
        }
    }
};

int main()
{
    Bank bank;

    int choice;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Open Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Money\n";
        cout << "5. Transaction History\n";
        cout << "6. Richest Customer\n";
        cout << "7. Display All Accounts\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.openAccount();
            break;

        case 2:
            bank.deposit();
            break;

        case 3:
            bank.withdraw();
            break;

        case 4:
            bank.transfer();
            break;

        case 5:
            bank.transactionHistory();
            break;

        case 6:
            bank.richestCustomer();
            break;

        case 7:
            bank.displayAllAccounts();
            break;

        case 8:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 8);

    return 0;
}
