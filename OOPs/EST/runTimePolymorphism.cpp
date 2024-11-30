#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow! Meow!" << endl;
    }
};

int main() {
    Animal* animal =new Animal();
    Dog dog;
    Cat cat;

    animal->makeSound();
    animal = &dog;
    animal->makeSound(); // Calls Dog's makeSound()

    animal = &cat;
    animal->makeSound(); // Calls Cat's makeSound()

    return 0;
}
