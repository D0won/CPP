#include<iostream>
#include<vector>
using namespace std;
class CBox {
public:
	int a;
	CBox(int x = 10) : a(x) {}	//
};

class CCandyBox : public CBox {
public :
	int b;
	CCandyBox(int x = 20) : CBox(x), b(x){}	//여기서 CBox(x)에서 20으로 초기화가 되고
	//위 CBox 에서 20으로 초기화 되며, a = 20 이 된다. 또한, 이 라인에서 b = 20이라는 값을 알게된다.
};

class CBeerBox : public CCandyBox {
public:
	int c;
	CBeerBox(int x) : c(x) {}	// c = 55
};
int main() {
	CBeerBox ee(55);
	cout << ee.a << " " << ee.b << " " << ee.c << " " << endl;

	return 0;
}	//20 20 55
