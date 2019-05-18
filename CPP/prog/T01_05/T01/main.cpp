// The 5th C++ program - main.cpp

#include <iostream>

using namespace std;

int main() {
    char myArray[50];

    cout << "What's your name? ";
    cin.getline(myArray, 50, '\n');

    if (!strcmp(myArray, "Ivan")) {
        strcat_s(myArray, "! How are you!\n");
    } else {
        strcat_s(myArray, "! Who are you?\n");
    }
    cout << myArray;

    system("pause");
}
