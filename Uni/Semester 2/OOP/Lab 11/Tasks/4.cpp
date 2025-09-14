#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw string("Error: Insufficient funds to complete withdrawal!");
        }
        balance -= amount;
        cout<<"Withdrawal successful! New Balance: $"<<balance<<endl;
    }

    void displayBalance() const {
        cout<<"Current Balance: $"<<balance<<endl;
    }
};

int main() {
    BankAccount account(500.0);

    account.displayBalance();
    cout<<"Enter withdrawal amount: $";
    double amount;
    cin >> amount;
    
    try {
        account.withdraw(amount);
    } catch (string errorMsg) {
        cout<<errorMsg<<endl;
        account.displayBalance();
    }

    cout<<"\nEnter withdrawal amount: $";
    cin >> amount;
    
    try {
        account.withdraw(amount);
    } catch (string errorMsg) {
        cout<<errorMsg<<endl;
        account.displayBalance();
    }

    return 0;
}