// The 4th C++ program - main.cpp

#include <iostream>

using namespace std;

int main() {
    int a, b;

    cout << "Enter a value for a: ";
    cin >> a;
    cout << "Enter a value for b: ";
    cin >> b;

    if (a > b) {
        cout << a << " is greater than " << b;
    } else if (a < b) {
        cout << a << " is less than " << b;
    } else {
        cout << a << " is equal to " << b;
    }
    cout << endl;

    system("pause");
}
