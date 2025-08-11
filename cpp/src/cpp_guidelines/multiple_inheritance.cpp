#include <iostream>

// 1. Diamond Problem 

class Animal
{
public:
    void Speak() { std::cout << "Animal sound\n"; }
};

class Dog : virtual public Animal {};
class Wolf : virtual public Animal {};

class WolfDog : public Dog, public Wolf {};

void TestAnimal()
{
    std::cout << "== Solved with Virtual Inheritance ==\n";
    WolfDog wd;
    wd.Speak();
}

// 3. Multiple Inheritance Without Diamond Problem

class Walkable
{
public:
    void Walk() { std::cout << "Walking...\n"; }
};

class Swimmable
{
public:
    void Swim() { std::cout << "Swimming...\n"; }
};

class Amphibian : public Walkable, public Swimmable {};

void TestWalkable()
{
    std::cout << "== Multiple Inheritance Without Diamond ==\n";
    Amphibian frog;
    frog.Walk();
    frog.Swim();
}

int main()
{
    TestAnimal(); 
    TestWalkable();
}
