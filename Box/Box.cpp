#include<iostream>
using namespace std;

void P3();

class Box {
private:
	int w, h, v_h;
public:
	Box(int a, int b, int c) : w(a), h(b), v_h(c)
	{
	}
	Box()
	{
		w = 1;
		h = 1;
		v_h = 1;
	}
	int getVolume()
	{
		return w * h * v_h;
	}

	void print()
	{
		cout << "밑면적 : " << w * h << " 상자 높이 : " << v_h << " 부피 : " << w * h * v_h << "\n";

	}
};
int main(void)
{
	P3();
	return 0;
}

void P3()
{
	Box b1(2, 3, 4), b2(4, 5, 6);
	Box b3;

	cout << "========================================" << endl;
	cout << "박스 1 "; b1.print();
	cout << "박스 2 "; b2.print();
	cout << "박스 3 "; b3.print();
	cout << "========================================" << endl;
	int vb1 = b1.getVolume();
	int vb2 = b2.getVolume();
	int vb3 = b3.getVolume();

	if (vb1 > vb2)
	{
		if (vb1 > vb3)
			cout << "박스1의 부피가 가장 큽니다 : " << vb1;
		else
			cout << "박스3의 부피가 가장 큽니다 : " << vb3;

	}
	else
	{
		if (vb2 > vb3)
			cout << "박스2의 부피가 가장 큽니다 : " << vb2;
		else
			cout << "박스3의 부피가 가장 큽니다 : " << vb3;

	}
}