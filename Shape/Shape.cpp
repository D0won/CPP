#include<iostream>
using namespace std;

class Point
{
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    void ReturnPoint()
    {
        cout << "("<< x << ", " << y << ")";
    }
};

class Shape
{
    Point p1, p2;
public:
    Shape(int a, int b, int c, int d) : p1(a, b), p2(c, d) {}
    void ReturnShape()
    {
        p1.ReturnPoint();
        cout << ", ";
        p2.ReturnPoint();
    }
};

class Line : public Shape
{
public:
    Line(int a, int b, int c, int d) : Shape(a, b, c, d) {}
    void Draw()
    {
        cout << "Line : ";
        Shape : ReturnShape();
        cout << "\n직선 그린다.\n";
    }
};

class Circle : public Shape
{
public:
    Circle(int a, int b, int c, int d) : Shape(a, b, c, d) {}
    void Draw()
    {
        cout << "Circle : ";
        Shape : ReturnShape();
        cout << "\n원 그린다.\n";
    }
};

void p8_2( ) { // main
    Circle a(1, 1, 5, 5); // 시작점, 끝점 좌표
    Line b(5, 5, 9, 9); // 시작점, 끝점 좌표
    a.Draw();// “원 그린다” , 시작점, 끝점 좌표 출력
    b.Draw();// “직선 그린다”, 시작점, 끝점 좌표 출력
}

int main(void)
{
    p8_2();
    return 0;
}