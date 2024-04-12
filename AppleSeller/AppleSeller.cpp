#include<iostream>
using namespace std;

void P3(void);

class FruitSeller {
private:
	int price, apple, money;
public:
	FruitSeller(int a, int b, int c): price(a),apple(b), money(c){}
	int SellApples(int a)
	{
		apple -= a/price;
		money += a;
		return price;
	}
	void ShowSalesResult()
	{
		cout << "남은 사과: " << apple << "\n";
		cout << "판매 수익: " << money << "\n";
	}
};
class FruitBuyer {
private:
	int money, apple;
public:
	FruitBuyer(int a, int b):money(a), apple(b){}
	void BuyApples(FruitSeller& s, int a)
	{
		int p = s.SellApples(a);
		money -= a;
		apple += a / p;
	}
	void ShowBuyResult()
	{
		cout << "현재 잔액: " << money << "\n";
		cout << "사과 개수: " << apple << "\n";
	}
};
int main(void)
{
	P3();
	return 0;
}

void P3(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000, 0);
	buyer.BuyApples(seller, 2000);
	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << endl;
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
}
