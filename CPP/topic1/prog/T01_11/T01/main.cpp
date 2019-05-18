// The 11th C++ program - main.cpp

#include <iostream>

using namespace std;

static int numDogs = 0;  // global variable to count dogs

class Dog {
    private:
        int age;
    public:
        Dog() {
            age = 1;
            numDogs++;
        }
        ~Dog() {
            numDogs--;
        }
        int getAge();
        void setAge(int a);
};

int Dog::getAge() { 
    return age;
}
 
void Dog::setAge(int a) {
    age = a;
}
 
int main() {
    Dog dog1;
    cout << numDogs << " dog(s)\n";

    dog1.setAge(5);
    cout << "dog1 is " << dog1.getAge() << " years old\n";

    {   Dog dog2;
        cout << numDogs << " dog(s)\n";
    }
    cout << numDogs << " dog(s)\n";

    system("pause"); 
} 
