#include<iostream>
using namespace std; 

class Point{
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    Point(const Point &obj) : x(obj.x), y(obj.y) {
        cout << "P\n";
    }
};

class Rec{
    Point p1, p2;
public:
    Rec(Point pp1, Point pp2) : p1(pp1), p2(pp2) {}
    Rec(const Rec &obj) :p1(obj.p1), p2(obj.p2) {
        cout <<"R\n";
    }
};

int main(void)
{
    Point pa(10, 20), pb(100, 200);
    Point pc = pb;
    Rec r1(pa, pb);
    Rec r2(pb, pa);
    Rec r3 = r1;

    return 0;
}
