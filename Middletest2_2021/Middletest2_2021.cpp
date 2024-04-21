#include<iostream>
using namespace std;

class Bat{
    int bb; //멤버 변수 bb의 선언
public:
    Bat(int m = 100) : bb(m) {} //생산자의 선언과동시에 초기화 
    void bil(Bat ot, int a); 
    void print() {cout << bb << endl;}
};

void Bat::bil(Bat ot, int a) // 같은 클래스의 멤버 함수라고 해도 매개변수 ot에는 값이 복사가 되므로 a2의 값은 변하지 않는다.
{
    bb -= a;
    ot.bb += a*10;
} 

int main(void)
{
    Bat a1(2000), a2;

    a1.bil(a2, 500);
    a1.print();
    a2.print();
    return 0;
}