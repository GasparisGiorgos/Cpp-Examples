#include <iostream>
using namespace std;

class BankAccount {
    public:
        // Give the ATM class a "VIP Key" to our private data
        friend class BankATM;

        BankAccount(double initial_money) {
            balance = initial_money;
        }

        double get_balance() const {
            return balance;
        }

    private:
        double balance; // Locked! Only the Account or its "Friends" can touch this.
};

class BankATM {
    public:
        // We pass the account by reference (BankAccount &acct) 
        // so we are touching the REAL account, not a photocopy.
        void deposit(BankAccount &acct, double amount) {
            acct.balance += amount; // This works ONLY because of the 'friend' line above.
        }
};

int main() {
    BankAccount my_savings(1000.00);
    BankATM central_atm;

    cout << "Balance before: $" << my_savings.get_balance() << endl;

    // We pass my_savings into the ATM
    central_atm.deposit(my_savings, 500.00);

    cout << "Balance after: $" << my_savings.get_balance() << endl;

    return 0;
}