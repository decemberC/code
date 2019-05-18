// The Third C++ Program - main.cpp

#include <iostream>

using namespace std;

int main() {
    char name[10];
    int myscore[3], ave;

    cout << "Please enter your name: (max 10 char): ";
    cin >> name;

    cout << "Please enter your Math score: ";
    cin >> myscore[0];

    cout << "Please enter your Chi score: ";
    cin >> myscore[1];

    cout << "Please enter your Eng score: ";
    cin >> myscore[2];

    ave = (myscore[0]+myscore[1]+myscore[2])/3;
    cout << name << ", your average score is: " << ave << endl;

    system("pause");
}
