#include<iostream>
using namespace std;

class gate
{
protected:
    bool x, y;
    bool z;
public:
    gate() : x(false), y(false), z(false) {} 
    void inputSet(bool a, bool b)
    {
        x = a;
        y = b;
    
    };
};

class ANDGate : public gate
{
public:
    void op()
    {
        z = x & y;
        cout << "AND input : " << x << " " << y << " -> " << z << "\n";
    }
};

class ORGate : public gate
{
public:
    void op()
    {
        z = x | y;
        cout << "OR input : " << x << " " << y << " -> " << z << "\n";
    }
};

class XORGate : public gate
{
public:
    void op()
    {
        z = x ^ y;
        cout << "XOR input : " << x << " " << y << " -> " << z << "\n";
    }
};

void p8_1() { 
    ANDGate gate_and;
    ORGate gate_or;
    XORGate gate_xor;
    gate_and.inputSet(true, false);
    gate_and.op();
    gate_and.inputSet(true, true);
    gate_and.op();
    gate_or.inputSet(true, false);
    gate_or.op();
    gate_or.inputSet(true, true);
    gate_or.op();
    gate_xor.inputSet(true, false);
    gate_xor.op();
    gate_xor.inputSet(true, true);
    gate_xor.op();
}

int main(void)
{
    p8_1();
    return 0;
}