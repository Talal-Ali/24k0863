#include <iostream>
#include <string>
using namespace std;
class Transaction;
class BankAccount {
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    string getAccountNumber(){
        return accountNumber;
    }

    double getBalance(){
        return balance;
    }
    friend void processTransaction(BankAccount &account, Transaction &transaction);
};

class Transaction {
    double amount;

public:
    Transaction(double amt) {
        amount = amt;
    }

    void deposit(BankAccount &account) {
        processTransaction(account, *this);
    }

    void withdraw(BankAccount &account) {
        processTransaction(account, *this);
    }

    double getAmount() const {
        return amount;
    }
};

void processTransaction(BankAccount &account, Transaction &transaction) {
    if (transaction.getAmount() < 0) {
        if (account.getBalance() + transaction.getAmount() >= 0) {
            account.balance += transaction.getAmount();
            cout << "Withdrawal of " << -transaction.getAmount() << " successful.\n";
        } else {
            cout << "Insufficient balance for withdrawal!\n";
        }
    } 
    else {
        account.balance += transaction.getAmount();
        cout << "Deposit of " << transaction.getAmount() << " successful.\n";
    }

    cout << "Updated balance: " << account.getBalance() << endl;
}

int main() {
    BankAccount account("12345", 500.00);  
    
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Initial Balance: " << account.getBalance() << endl;
    
    Transaction depositTransaction(200.00);  
    Transaction withdrawalTransaction(-100.00); 

    depositTransaction.deposit(account);
    withdrawalTransaction.withdraw(account);

    return 0;
}
