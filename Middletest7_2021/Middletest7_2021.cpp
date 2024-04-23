#include<iostream>
using namespace std;

class Point{
    int x, y;
public:
    Point(int a, int b) : x(a), y(b){
        // x = a; <- 이것도 되고
        // y = b; <- 이것도 됨
    }
    int GetX() {return x; }
    int GetY() {return y; }
};

class Rect{
    Point leftUp, rightLow;
    int color;
public:
    Rect(int a, int b, int c, int d, int e);
    void ShowRect();
};

Rect::Rect(int a, int b, int c, int d, int e) : leftUp(a,b), rightLow(c, d), color(e)
{

}                                                                                                                                                                                                                                                                                                                                                         
void Rect::ShowRect() {
    cout << "좌상단점 좌표 :" << leftUp.GetX() <<" " << leftUp.GetY() << "\n";
    cout << "우하단점 좌표 :" << rightLow.GetX() <<" " << rightLow.GetY() << "\n";
    cout << "면색 :" << this->color << "\n";
      
}

int main() {
    Rect a(10, 20, 30, 40, 1), b(10, 10, 20, 20, 2);
    a.ShowRect();
    b.ShowRect();
    return 0;
}