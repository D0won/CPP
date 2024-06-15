#include <iostream>
#include<vector>

using namespace std;
//1번
class BankA {
   int money;

public:
   BankA(int m = 100) : money(m) {}
   void Tf(BankA b1, BankA& b2, int a);
   void print() { cout << money << " "; }
};

void BankA::Tf(BankA b1, BankA& b2, int a) {
   money -= (a + a);   //x1으로 호출하엿으니 x1의 money를 가르킨다. 2000 - (500+500) = 1000
   b1.money += a;  //얕은 복사이다. b1과 x2는 독립적이므로 값변화가 없다. 1000
   b2.money += a;  //호출이 제대로 되며,100 + 500 으로 600이다
}
  
int main() {
   BankA x1(2000), x2(1000), x3;

   x1.Tf(x2, x3, 500); // 여기서 즉, x2 = b1이라는 얕은 복사가 일어난다.
   x1.print(); // 2000-1000(500+500)
   x2.print();
   x3.print(); //100+500

   return 0;
}   //1000 1000 600
