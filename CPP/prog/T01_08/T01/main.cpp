// The 8th C++ program - mian.cpp

#include <iostream>

using namespace std;

int addNumbers(int a, int b) {
    return(a+b);
}

int main() {
    int a, b;

    cout << "Enter a number: ";
    cin >> a;

    cout << "Enter an other number: ";
    cin >> b;

    cout << "Sum of the two numbers is: " << addNumbers(a, b) << "\n";

    system("pause");
}