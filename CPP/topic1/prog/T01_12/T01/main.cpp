// The 12th C++ program - main.cpp

#include "adder.h"
#include <iostream>

using namespace std;

int main() {
    Adder a1, a2;

    a1.seta(2);
    a1.setb(5);
    a2.seta(1);
    a2.setb(5);

    cout << a1.addNumber() << endl;
    cout << a2.addNumber() << endl;

    system("pause");
}
