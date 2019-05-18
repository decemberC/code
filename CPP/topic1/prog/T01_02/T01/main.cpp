// The Second C++ Program - main.cpp

#include <iostream>

using namespace std;

int main() {
    int chi, eng;
    float math, ave;

    cout << "Hello World!\n";

    cout << "\n Please enter your math score: "; //read the mark from user
    cin >> math;

    cout << "\n Please enter your chi score: "; //read the mark from user
    cin >> chi;

    cout << "\n Please enter your eng score: ";
    cin >> eng;   

    ave = (math + chi + eng)/3;
    cout << "\n Your average marks: " << ave << endl;

    system("pause");
}
