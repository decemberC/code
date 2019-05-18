// The Class Exercise - main.cpp

#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        double score[3];
    public:
        string name;
        int id;
        void setScore(double s, int n);
        double getScore(int n);
        double average();
};


void Student::setScore(double s, int n) {
    score[n] = s;
}


double Student::getScore(int n) {
    return score[n];
}


double Student::average() {
    double sum = 0.0;
    int i;
    for (i=0; i<3; i++)
        sum += score[i];
    return sum/i;
}


int main() {
    Student stud[3];

    stud[0].name = "Chan Siu Ming";
    stud[0].id = 310567;
    stud[0].setScore(87.2,0);
    stud[0].setScore(85.4,1);
    stud[0].setScore(88.4,2);

    stud[1].name = "Ng Wai Man";
    stud[1].id = 451267;
    stud[1].setScore(77.6,0);
    stud[1].setScore(74.2,1);
    stud[1].setScore(71.1,2);

    stud[2].name = "Wong Sui Kai";
    stud[2].id = 789014;
    stud[2].setScore(83.6,0);
    stud[2].setScore(77.4,1);
    stud[2].setScore(69.1,2);

    for (int i=0; i<3; i++) {
        cout << "Student " << i+1;
        cout << ": name=" << stud[i].name;
        cout << ", id=" << stud[i].id;
        cout << ", average=" << stud[i].average() << endl;
    }

    system("pause");
}
