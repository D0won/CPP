#include<iostream>
using namespace std;

class Point{
public:
    int x, y;
    Point(int xx =2, int yy = 4) : x(xx), y(yy) {}
    void print(){
        cout << x << " " << y << endl;
    }
};

void cha(Point &a, Point b){
    Point t;
    t.x = a.x;
    a.x = b.x;
    b.x = t.x;
    t.y = a.y;
    a.y = b.y;
    b.y = t.y;
}

int main(){
    Point a(3,6), b;
    cha(b, a);
    a.print();
    b.print();
    return 0;
}