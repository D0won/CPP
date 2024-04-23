#include<iostream>
using namespace std;

class myclass{
    int a, b;
public:
    myclass(int x = 0, int y = 0) : a(x), b(y) {
        cout << "생성자 호출\n";
    }
    myclass(const myclass & obj) : a(obj.a), b(obj.b) {
        cout << "복사생성자 호출\n";
    }
    ~myclass()
    {
        cout << "소멸자 호출\n";
    }

};



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
    delete n4;
    return 0;
}