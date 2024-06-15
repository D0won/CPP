#include<iostream>
#include<vector>
using namespace std;

int main() {
	int data[] = { 10, 20, 30, 40, 50 };
	vector<int> aa(data, data + 2);

	for (int i = 0; i < 2; i++) {
		aa.push_back(i + 1);
	}
	vector <int>::iterator ita;
	for (ita = aa.begin(); ita != aa.end(); ita++)
		cout << *(ita) << " ";
	cout << endl;
}
