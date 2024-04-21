#include<iostream>
using namespace std;

class Complex{
    double real, image;
    static int count;
public:
    Complex(double r = 0, double i = 0) : real(r), image(i){
        count++;
    }
    ~Complex(){
        count--;
    }
    int GetRealAdd(Complex &a, Complex b){
        double r = a.real + b.real;
        return r;
    }       
    int GetCount(){
        return count;
    }
};
int Complex::count = 0;

int main(){
    Complex com1(1.0, 2.0), com2(3.0, 4.0);
    double ret = com1.GetRealAdd(com1, com2);

    Complex* pcom4 = new Complex;
    cout << com1.GetCount() << endl;
    delete pcom4;
    cout << com1.GetCount() << endl;
}
