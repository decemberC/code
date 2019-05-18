// The 9th C++ program - main.cpp

#include <iostream>

using namespace std;

int main() {
    int *address;
    int value = 200;

    address = &value;

    cout << "value = " << value << endl;
    cout << "&value = " << &value << endl;
    cout << "*address = " << *address << endl;
    cout << "address = " << address << endl;

    system("pause");
}
