#include<iostream>
using namespace std;

class AndGate // AND 게이트 클래스
{
	int x, y;
	int output;
public:
	AndGate() : x(0), y(0), output(0) {} //초기화 시키는 생성자
	void input(int a, int b); // 정수로 x,y를 받는 함수
	int op(); // Output을 반환하는 함수
};

class OrGate
{
	int x, y;
	int output;
public:
	OrGate() : x(0), y(0), output(0) {} // 초기화 시키는 생성자
	void input(int a, int b); // 정수를 받는 input 함수
	void input(AndGate a, AndGate b); // AndGate의 객체를 받는 input 함수(오버로딩)
	int op(); // Output을 반환하는 함수
};

void AndGate::input(int a, int b) // 정수를 받음
{
	x = a; 
	y = b;
}

int AndGate::op() 
{
	output = x & y; // 비트연산자를 이용해 AND 게이트를 구현 및 결과값을 output에 넣음.
	cout << "AND input : " << x << " " << y << " -> " << output << "\n"; // 출력
	return output; // 결과값을 반환시킴
}


void OrGate::input(int a, int b) // 정수를 받음
{
	x = a;
	y = b;
}

void OrGate::input(AndGate a, AndGate b) // AndGate의 객체를 받음
{
	y = a.op(); // 객체 a의 op함수를 통해 output을 받음
	x = b.op(); // 객체 b의 op함수를 통해 output을 받음
}

int OrGate::op()
{
	output = x | y; // 비트연산자를 이용해 OR 게이트를 구현 및 결과값을 output에 넣음.
	cout << "OR input : " << x << " " << y << " -> " << output << "\n"; // 출력
	return output; // 결과값을 반환시킴
}

int main()
{
	AndGate a_and, b_and;
	OrGate c_or;
	a_and.input(1, 0);
	a_and.op();
	b_and.input(1, 1);
	b_and.op();
	c_or.input(1, 0);
	c_or.op();
	c_or.input(a_and, b_and);
	c_or.op();
	return 0;
}

