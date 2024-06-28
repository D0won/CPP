#include <iostream>
#include<vector>

using namespace std;

template <typename T1, typename T2>
T1 PrintData(T1 data1, T2 data2) {
	T1 ret = data1;
	cout << data2 << " ";
	return ret;
}

int  main() {
	int a = PrintData(5, "안녕");
	cout << a << endl;

	string b = PrintData("안녕", 5);
	cout << b << endl;
}
