#include <iostream>
#include<vector>

using namespace std;

class Mammal {
protected:
    int Age;

public:
    Mammal() : Age(1) {}
    virtual void Speak() const { cout << "어흥" << " "; }
};

class Dog : public Mammal {
public:
    Dog() {}
    void Speak() const override { cout << "멍멍" << " "; }
};

class Pig : public Mammal {
public:
    Pig() {}
    void Speak() const override { cout << "꿀꿀" << " "; }
};

int main() {
    Mammal* pDog = new Dog;
    pDog->Speak();  // Dog 클래스의 Speak 함수가 호출됨. 출력: 멍멍


    pDog = new Pig;
    pDog->Speak();  // Pig 클래스의 Speak 함수가 호출됨. 출력: 꿀꿀
    delete pDog;

    return 0;
}