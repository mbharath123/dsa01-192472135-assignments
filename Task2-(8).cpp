#include <iostream>
using namespace std;

// Original approach: shifting the array when it is full.
class ShiftHistory {
    int data[10]{};
    int count = 0;
public:
    void add(int value) {
        if (count < 10) data[count++] = value;
        else {
            for (int i = 1; i < 10; ++i) data[i - 1] = data[i];
            data[9] = value;
        }
    }
    void display() const {
        for (int i = 0; i < count; ++i) cout << data[i] << ' ';
        cout << '\n';
    }
};

// Redesigned circular buffer: insertion is O(1), fixed storage remains O(10).
class CircularHistory {
    int data[10]{};
    int start = 0;
    int count = 0;
public:
    void add(int value) {
        if (count < 10) {
            data[(start + count) % 10] = value;
            ++count;
        } else {
            data[start] = value;
            start = (start + 1) % 10;
        }
    }
    void display() const {
        for (int i = 0; i < count; ++i)
            cout << data[(start + i) % 10] << ' ';
        cout << '\n';
    }
};

int main() {
    ShiftHistory original;
    CircularHistory redesigned;

    for (int i = 1; i <= 15; ++i) {
        original.add(i);
        redesigned.add(i);
    }

    cout << "Original (shift): ";
    original.display();
    cout << "Redesigned (circular): ";
    redesigned.display();
    return 0;
}