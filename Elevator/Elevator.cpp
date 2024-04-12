#include<iostream>
using namespace std;
class Elevator
{
	int floor, button; // 현재 층을 받는 변수(floor)와 갈려고하는 층을 받는 변수(button)
public:
	Elevator(int cur):floor(cur), button(cur){} // 생성자로 floor 변수와 button 변수를 현재층으로 초기화
	void Button(int a); // 갈려고 하는 층을 받는 변수
	void CloseDoor(); // 엘리베이터 문이 닫힐 때까지 그 층까지 가는 과정을 출력하는 함수 
};

void Elevator::Button(int a)
{
	button = a; // button 변수에 갈려고 하는 층을 받음
}

void Elevator::CloseDoor()
{
	
	if (floor > button) // 현재 층이 갈려고 하는 층보다 높은 경우 
	{
		for (int i = floor; i >= button; i--)
		{
			cout << "현재층:" << i<<"\n";
		}
	}
	else // 현재 층이 갈려고 하는 층보다 낮은 경우
	{
		for (int i = floor; i <= button; i++)
		{
			cout << "현재층:" << i << "\n";
		}
	}
	floor = button; // 갈려고 하는 층에 도달했으면 현재 층을 도달한 층으로 바꾼다.
}
int main(void)
{
	Elevator a(1), b(8);
	a.Button(6);
	a.CloseDoor();
	cout << endl;

	b.Button(3);
	b.CloseDoor();
	return 0;
}
