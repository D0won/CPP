#include<iostream>
using namespace std;

class Vector
{
    int x, y;
public:
    Vector(int x = 0, int y = 0) : x(x), y(y) {}
    void print() const { cout << x << ", " << y << "\n"; }
    friend ostream& operator<<(ostream& os, const Vector& v);

    Vector operator+(const Vector& v) const
    {
        return Vector(x + v.x, y + v.y);
    }

    Vector operator +=(const Vector& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    
    Vector operator-(const Vector& v) const
    {
        return Vector(x - v.x, y - v.y);
    }

    Vector operator-=(const Vector& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector operator*(int n) const
    {
        return Vector(x * n, y * n);
    }

    bool operator==(const Vector& v) const
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vector& v) const
    {
        return !(*this == v);
    }

};

ostream& operator<<(ostream& os, const Vector& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

void p10_1(){
    Vector a(1, 2), b(2, 3), c;
    c = a - b;
    cout << a << " , " << b << " , " << c << "\n";

    a +=b;
    cout << a << " , " << b << " , " << c << "\n";

    a+=c;
    cout << a << " , " << b << " , " << c << "\n";
}

int main(void)
{
    p10_1();
    return 0;
}