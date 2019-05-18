// The 6th C++ program - main.cpp

#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "How many times do you want the loop to run? ";
    cin >> a;

    while (a>0) {
        cout << a << "\n";
        --a;
    }

    system("pause");
}
