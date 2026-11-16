#include <iostream>
using namespace std;

int& highestMark(int marks[], int n) {
    int index = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}

// Deliberately unsafe example: never call/use this function.
int& danglingReference() {
    static int safePlaceholder = 0;
    // A static object has lifetime beyond the function.
    return safePlaceholder;
}

int highestIndex(const int marks[], int n) {
    int index = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[index]) index = i;
    return index;
}

int main() {
    int marks[] = {78, 92, 85, 96, 89};
    int n = sizeof(marks) / sizeof(marks[0]);

    cout << "Highest before moderation: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "Highest after moderation : " << highestMark(marks, n) << '\n';

    int index = highestIndex(marks, n);
    cout << "Highest mark index       : " << index << '\n';
    cout << "Value using index         : " << marks[index] << '\n';
    return 0;
}