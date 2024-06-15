#include <iostream>
#include<vector>
using namespace std;

class Vec {
	int* data;	int size;	
public:
	Vec(int s) : size(s) {
		data = new int[size];	
	}
	~Vec() {
		delete[] data;
	}
	
	int& operator[](int index) { return data[index]; }

	Vec& operator+=(Vec& v) {
		for (int i = 0; i < size; i++)
			data[i] = data[i] - v[i];	
		return *this;
	};
friend void operator<<(ostream& os, Vec& v);
};
void operator<<(ostream& os, Vec& v) {	
	for (int i = 0; i < v.size; i++)
		os << v[i] << " ";	
}

int main() {
	int k = 2;	
	Vec v1(k), v2(k);
	for (int i = 0; i < k; i++) {
		v1[i] = 10; v2[i] = i;	// 10 10 0 1
	}
	v2 += v1; // v2 = 10 9 v1 = 0 1
	cout << v2; // 10 9
	return 1;
}	