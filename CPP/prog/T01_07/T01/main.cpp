// The 7th C++ program - main.cpp

#include <iostream>

using namespace std;

int main() {
    int myArray[10][10];

    for (int i=0; i<=9; i++) {
        for (int t=0; t<=9; t++) {
            myArray[i][t] = i*10+t;     //This will give each element a value
        }
    }

    for (int i=0; i<=9; i++) {
        for (int t=0; t<=9; t++) {
            cout << myArray[i][t] << endl;
        }
    }

    system("pause");
}
