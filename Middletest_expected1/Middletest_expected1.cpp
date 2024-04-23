#include<iostream>
using namespace std;

class myclass{
    int a, b;
    static int n;
public:
    myclass(int x = 0, int y = 0) : a(x), b(y) {
        n++;
    }
    myclass(const myclass & obj) : a(obj.a), b(obj.b) {
        n--;
    }
    ~myclass()
    {
        n--;
    }
    void Print()
    {
        cout << n << "\n";
    }
};

int myclass:: n = 0;

myclass Value(myclass obj)
{
    myclass t;
    t = obj;
    return t;
}

int main(void)
{
    myclass n1(1, 1), n2(2, 0);
    myclass n3 = Value(n2);
    myclass *n4 = new myclass;
    *(n4) = Value(n2);
    n4->Print();
    delete n4;
    n1.Print();
    return 0;
}