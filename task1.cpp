
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum class Zone { Inner = 1, Middle, Outer, Airport };
enum class Passenger { Regular = 1, Student, Senior };

const long long MIN_BALANCE = 5000;
const int PEAK_RATE = 20;
const int WEEKEND_DISCOUNT = 10;

// Base fares in paise
long long baseFare(Zone z) {
    switch (z) {
        case Zone::Inner: return 1000;
        case Zone::Middle: return 2000;
        case Zone::Outer: return 3000;
        case Zone::Airport: return 6000;
    }
    return 0;
}

string zoneName(Zone z) {
    switch (z) {
        case Zone::Inner: return "Inner";
        case Zone::Middle: return "Middle";
        case Zone::Outer: return "Outer";
        case Zone::Airport: return "Airport";
    }
    return "Invalid";
}

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(Zone z, int hour, bool weekend) {
    long long fare = baseFare(z);

    // Weekend discount does not combine with peak surcharge
    if (weekend) {
        fare = fare * (100 - WEEKEND_DISCOUNT) / 100;
    } else if (isPeak(hour)) {
        fare = fare * (100 + PEAK_RATE) / 100;
    }

    return fare;
}

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long amount) {
        balance = amount;
    }

    long long getBalance() {
        return balance;
    }

    bool canTravel(long long fare) {
        return balance - fare >= MIN_BALANCE;
    }

    bool deductFare(long long fare) {
        if (!canTravel(fare))
            return false;

        balance -= fare;
        return true;
    }

    void recharge(long long amount) {
        if (amount > 0)
            balance += amount;
    }
};

class MonthlyPass {
private:
    bool active = false;
    Zone zone1, zone2;
    int month, year;

public:
    void activate(Zone z1, Zone z2, int m, int y) {
        if (z1 == z2 || m < 1 || m > 12 || y < 2026) {
            cout << "Invalid pass details!\n";
            return;
        }

        zone1 = z1;
        zone2 = z2;
        month = m;
        year = y;
        active = true;

        cout << "Monthly pass activated successfully!\n";
    }

    bool covers(Zone z, int m, int y) {
        return active && month == m && year == y &&
               (z == zone1 || z == zone2);
    }

    void display() {
        if (!active) {
            cout << "No active monthly pass.\n";
            return;
        }

        cout << "Pass Zones: " << zoneName(zone1)
             << " and " << zoneName(zone2) << "\n";
        cout << "Valid Month: " << month << "/" << year << "\n";
    }
};

int main() {
    long long amount;

    cout << "================================\n";
    cout << "   CITY METRO SMART CARD SYSTEM\n";
    cout << "================================\n";

    cout << "Enter initial balance (Rs): ";
    if (!(cin >> amount) || amount < 50) {
        cout << "Invalid balance!\n";
        return 0;
    }

    SmartCard card(amount * 100);
    MonthlyPass pass;

    int choice;

    do {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Book Journey\n";
        cout << "2. Recharge Card\n";
        cout << "3. View Balance\n";
        cout << "4. Activate Monthly Pass\n";
        cout << "5. View Monthly Pass\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice) {
        case 1: {
            int zone, hour, passenger, month, year;
            char weekendInput;

            cout << "\n1.Inner  2.Middle  3.Outer  4.Airport\n";
            cout << "Select zone: ";
            cin >> zone;

            if (zone < 1 || zone > 4) {
                cout << "Invalid zone!\n";
                break;
            }

            cout << "Enter hour (0-23): ";
            cin >> hour;

            if (hour < 0 || hour > 23) {
                cout << "Invalid hour!\n";
                break;
            }

            cout << "Weekend? (y/n): ";
            cin >> weekendInput;

            if (weekendInput != 'y' && weekendInput != 'Y' &&
                weekendInput != 'n' && weekendInput != 'N') {
                cout << "Invalid weekend input!\n";
                break;
            }

            cout << "1.Regular  2.Student  3.Senior\n";
            cout << "Select passenger type: ";
            cin >> passenger;

            if (passenger < 1 || passenger > 3) {
                cout << "Invalid passenger type!\n";
                break;
            }

            Zone selected = static_cast<Zone>(zone);

            cout << "Enter month and year: ";
            cin >> month >> year;

            if (month < 1 || month > 12 || year < 2026) {
                cout << "Invalid date!\n";
                break;
            }

            if (pass.covers(selected, month, year)) {
                cout << "Monthly pass applied. Fare: Rs 0.00\n";
                break;
            }

            long long fare = calculateFare(
                selected, hour,
                weekendInput == 'y' || weekendInput == 'Y'
            );

            cout << fixed << setprecision(2);
            cout << "Zone: " << zoneName(selected) << "\n";
            cout << "Fare: Rs " << fare / 100.0 << "\n";

            if (card.deductFare(fare)) {
                cout << "Journey successful!\n";
            } else {
                cout << "Journey denied! Minimum Rs 50 must remain.\n";
            }

            cout << "Remaining Balance: Rs "
                 << card.getBalance() / 100.0 << "\n";
            break;
        }

        case 2: {
            long long recharge;
            cout << "Enter recharge amount (Rs): ";
            cin >> recharge;

            if (recharge <= 0 || recharge > 1000000) {
                cout << "Invalid recharge amount!\n";
            } else {
                card.recharge(recharge * 100);
                cout << "Recharge successful!\n";
            }
            break;
        }

        case 3:
            cout << fixed << setprecision(2);
            cout << "Current Balance: Rs "
                 << card.getBalance() / 100.0 << "\n";
            break;

        case 4: {
            int z1, z2, month, year;
            cout << "Select two zones (1-4): ";
            cin >> z1 >> z2;
            cout << "Enter month and year: ";
            cin >> month >> year;

            if (z1 < 1 || z1 > 4 || z2 < 1 || z2 > 4) {
                cout << "Invalid zones!\n";
            } else {
                pass.activate(static_cast<Zone>(z1),
                              static_cast<Zone>(z2),
                              month, year);
            }
            break;
        }

        case 5:
            pass.display();
            break;

        case 6:
            cout << "Thank you for using Metro Smart Card!\n";
            break;

        default:
            cout << "Invalid menu choice!\n";
        }

    } while (choice != 6);

    return 0;
}
