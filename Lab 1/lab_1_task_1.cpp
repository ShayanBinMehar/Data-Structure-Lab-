#include <iostream>
using namespace std;

class Account {
private:
    double funds;

public:
    Account() {
        funds = 0.0;
    }

    Account(double opening) {
        funds = opening;
    }

    Account(const Account &src) {
        funds = src.funds;
    }

    void withdraw(double value) {
        funds -= value;
    }

    double showBalance() const {
        return funds;
    }
};

int main() {
    Account acc1;
    cout << "Account 1 Balance: $" << acc1.showBalance() << endl;

    Account acc2(1000.0);
    cout << "Account 2 Balance: $" << acc2.showBalance() << endl;

    Account acc3(acc2);
    acc3.withdraw(200);
    cout << "Account 3 Balance after withdrawing $200: $" 
         << acc3.showBalance() << endl;

    cout << "Account 2 Balance remains: $" << acc2.showBalance() << endl;

    return 0;
}
