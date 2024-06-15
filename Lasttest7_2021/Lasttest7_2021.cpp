#include <iostream>
#include<vector>
using namespace std;

class Tmp {
	int x;
public:
	Tmp(int a):x(a){}
	Tmp operator++() { // 전위
		x += 10;
		return *this;
	}
	const Tmp operator++(int) { // 후위
		Tmp ret = *this;
		x += 10;
		return ret;
	}
	friend ostream& operator<<(ostream& os, const Tmp& v);
};

ostream& operator<<(ostream& os, const Tmp& v) {
	os << v.x << endl;
	return os;
}
int main() {
	Tmp b(0);

	cout << (++(++b))++;
	cout << b;	

	return 0;
}	// 
