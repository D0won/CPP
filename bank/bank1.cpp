#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20; // 이름의 길이를 20으로 정의

void ShowMenu(void);       // 메뉴출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);       // 입    금
void WithdrawMoney(void);      // 출    금
void ShowAllAccInfo(void);     // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; // 열거형으로 Make는 1, Deposit는 2, Withdraw는 3, Inquire는 4, Exit는 5이다.

class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char* cusName;   // 고객이름

public:
	Account(int ID, int money, char* name) // 생성자로 ID, money, name을 받아서 초기화
		: accID(ID), balance(money) 
	{
		cusName = new char[strlen(name) + 1]; // name의 길이 + 1만큼 cusName에 메모리 할당
		strcpy_s(cusName, (strlen(name) + 1), name); // name을 cusName에 복사
	}

	Account(const Account& ref) // 복사 생성자
		: accID(ref.accID), balance(ref.balance) // accID, balance를 ref의 accID, balance로 초기화
	{
		cusName = new char[strlen(ref.cusName) + 1]; // ref의 cusName의 길이 + 1만큼 cusName에 메모리 할당
		strcpy_s(cusName, (strlen(ref.cusName) + 1), ref.cusName); // ref의 cusName을 cusName에 복사
	}

	int GetAccID() const { return accID; } // accID 반환

	void Deposit(int money) // 입금액을 받아 잔액에 더함
	{
		balance += money;
	}

	int Withdraw(int money)    // 출금액 반환, 부족 시 0 반환, 출금액만큼 현재 잔액에서 뺌
	{
		if (balance < money) 
			return 0;

		balance -= money; 
		return money;
	}

	void ShowAccInfo() const // 계좌정보 출력
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << cusName << endl;
		cout << "잔  액: " << balance << endl;
	}

	~Account() // 소멸자로 cusName 메모리 해제
	{
		delete[]cusName;
	}
};

Account* accArr[100];   // Account 저장을 위한 배열
int accNum = 0;        // 저장된 Account 수

int main(void)
{
	int choice; // 메뉴 선택을 위한 변수

	while (1)
	{
		ShowMenu(); // 메뉴 출력
		cout << "선택: "; 
		cin >> choice; // 메뉴 선택
		cout << endl;

		switch (choice) // 선택에 따른 함수 호출
		{
		case MAKE: 
			MakeAccount(); // 계좌개설
			break;
		case DEPOSIT:
			DepositMoney(); // 입금
			break;
		case WITHDRAW:
			WithdrawMoney(); // 출금
			break;
		case INQUIRE:
			ShowAllAccInfo(); // 계좌정보조회
			break;
		case EXIT: // 프로그램 종료
			return 0;
		default: // 잘못된 선택
			cout << "Illegal selection.." << endl;
		}
	}

	for (int i = 0; i < accNum; i++) // 메모리 해제
		delete accArr[i];
	return 0;
}

void ShowMenu(void) // 메뉴 출력
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id; // 계좌번호
	char name[NAME_LEN]; // 이름
	int balance; // 잔액

	//계좌개설 시 필요한 정보 입력받기
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name); // Account 객체 생성 후 배열에 저장
}

void DepositMoney(void)
{
	int money; // 입금액
	int id; // 계좌번호

	// 입금 시 필요한 정보 입력받기
	cout << "[입    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++) // 만들어진 계좌 개수만큼 반복
	{
		if (accArr[i]->GetAccID() == id) // 계좌번호가 일치하는 경우 입금
		{
			accArr[i]->Deposit(money); // 입금액만큼 입금
			cout << "입금완료" << endl << endl; // 입금완료 출력
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl; // 계좌번호가 일치하지 않는 경우 출력
}

void WithdrawMoney(void)
{
	int money; // 출금액
	int id; // 계좌번호

	// 출금 시 필요한 정보 입력받기
	cout << "[출    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++) // 만들어진 계좌 개수만큼 반복 
	{ 
		if (accArr[i]->GetAccID() == id) // 계좌번호가 일치하는 경우 출금
		{
			if (accArr[i]->Withdraw(money) == 0) // 출금액이 잔액보다 많은 경우
			{
				cout << "잔액부족" << endl << endl; // 잔액부족 출력
				return; // 함수 종료
			}

			cout << "출금완료" << endl << endl; // 출금완료 출력
			return; // 함수 종료
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl; // 계좌번호가 일치하지 않는 경우 출력
}

void ShowAllAccInfo(void) // 계좌정보 전체 출력
{
	for (int i = 0; i < accNum; i++) // 만들어진 계좌 개수만큼 반복
	{
		accArr[i]->ShowAccInfo(); 
		cout << endl;
	}
}