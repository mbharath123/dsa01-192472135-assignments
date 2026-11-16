#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {
        if (h < 0 || h > 23 || m < 0 || m > 59) {
            h = 0;
            m = 0;
        }
    }

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return abs(first - second);
}

inline bool earlier(const Time& a, const Time& b) {
    return (a.h * 60 + a.m) < (b.h * 60 + b.m);
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time noonBefore(11, 50), noonAfter(12, 10);
    cout << minutesBetween(noonBefore, noonAfter) << ' '
         << earlier(noonBefore, noonAfter) << '\n';

    Time same1(14, 30), same2(14, 30);
    cout << minutesBetween(same1, same2) << ' '
         << earlier(same1, same2) << '\n';
    return 0;
}