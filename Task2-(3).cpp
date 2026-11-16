#include <iostream>
#include <string>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

// One unambiguous core function with default arguments.
double charge(double weightKg, bool express = false, bool insured = false) {
    double total = weightKg * 40.0;
    if (express) total += 50.0;
    if (insured) total += 25.0;
    return total;
}

// Explicitly named overloads for different input types.
double chargeGrams(int weightGrams) {
    return charge(weightGrams / 1000.0);
}

double chargeParcel(const Parcel& p) {
    return charge(p.weightKg, p.express, p.insured);
}

int main() {
    cout << "charge(2)       = " << charge(2) << '\n';
    cout << "charge(2.0f)    = " << charge(static_cast<double>(2.0f)) << '\n';
    cout << "charge(2,true)  = " << charge(2.0, true) << '\n';
    cout << "charge(2,true,true) = " << charge(2.0, true, true) << '\n';
    cout << "chargeGrams(500) = " << chargeGrams(500) << '\n';

    Parcel p{3.0, true, false};
    cout << "chargeParcel    = " << chargeParcel(p) << '\n';
    return 0;
}