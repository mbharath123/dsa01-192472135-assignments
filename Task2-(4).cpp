#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balance;       // stored in paise
    long long transactions[10];
    int count;

    void record(long long amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(const string& number, long long openingPaise)
        : accountNumber(number), balance(openingPaise), count(0) {}

    void deposit(long long amountPaise);
    bool withdraw(long long amountPaise);
    void miniStatement() const;
};

void SavingsAccount::deposit(long long amountPaise) {
    if (amountPaise <= 0) {
        cout << "Invalid deposit\n";
        return;
    }
    balance += amountPaise;
    record(amountPaise);
}

bool SavingsAccount::withdraw(long long amountPaise) {
    if (amountPaise <= 0 || amountPaise > balance) {
        cout << "Withdrawal rejected\n";
        return false;
    }
    balance -= amountPaise;
    record(-amountPaise);
    return true;
}

void SavingsAccount::miniStatement() const {
    cout << "\nAccount: " << accountNumber << '\n';
    cout << "Balance: Rs " << fixed << setprecision(2)
         << balance / 100.0 << '\n';
    cout << "Recent transactions (Rs):\n";
    for (int i = 0; i < count; ++i)
        cout << (transactions[i] >= 0 ? "+ " : "- ")
             << fixed << setprecision(2)
             << (transactions[i] >= 0 ? transactions[i] : -transactions[i]) / 100.0
             << '\n';
}

int main() {
    SavingsAccount account("SB1001", 500000);
    account.deposit(100000);
    account.withdraw(25000);
    for (int i = 1; i <= 10; ++i) account.deposit(i * 1000);
    account.miniStatement();
    return 0;
}