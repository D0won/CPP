#include<bits/stdc++.h>
using namespace std;

class Mammal {
protected:
	int Age;
public:
	Mammal():Age(1){}
	void Speak() const { cout << "어흥" << " "; }
};

class Dog : public Mammal {
public:
	Dog(){}
	void Speak() const { cout << "멍멍" << " "; }
};

class Pig : public Mammal {
public:
	Pig() {}
	void Speak() const { cout << "꿀꿀" << " "; }
};

int main() {
	Mammal* pDog = new Dog;	//상향 형변환(자식이 부모로 위장.),
	//부모로 위장했으니 부모역할만 가능.
	pDog->Speak();

	pDog = new Pig;
	pDog->Speak();
	return 0;	//어흥 어흥
}
