#include <iostream>
#include<vector>

using namespace std;

class First {
public:
	First() { cout << "a" << ""; } //1		4
	~First() { cout << "b" << ""; } //3		7
};

class Second : public First {	//상속 부분.
public:
	Second() { cout << "c" << ""; } //2		5
	~Second() { cout << "d" << ""; }	//6
};

int main(void) {
	First* ptr_1 = new Second;
	delete ptr_1;

	Second* ptr_2 = new Second;	//생성할때는 부모가 먼가 생성되고, 그 후에 자식이 한다.
	delete ptr_2;	// 제거시에는 자식 먼저 제거후에 부모를 제거한다.

	return 0;
}	//a c b    a c d b(부모 상속 개념 때문에 순서가 이렇다.)

