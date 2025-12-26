#include <iostream>

class Animal {
public:

    virtual void makeSound() {
        std::cout << "Animal makes a sound\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Animal* basePtr;

    Dog dog;
    Cat cat;

    basePtr = &dog;          
    basePtr->makeSound();   

    basePtr = &cat;         
    basePtr->makeSound();   

    Animal animal;
    animal.makeSound();    

    return 0;
}
