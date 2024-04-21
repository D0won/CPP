#include<iostream>
using namespace std;

int& funcOne(int& var) {
    var++;
    return var;
}

int main() {
    int n = 100;
    int k = funcOne(n);

    n++;
    cout << n << " " << k << endl;
}