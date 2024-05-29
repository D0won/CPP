#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20; // 이름의 길이를 20으로 정의

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; // 열거형으로 Make는 1, Deposit는 2, Withdraw는 3, Inquire는 4, Exit는 5이다.


/*
 * 클래스 이름: Account
 * 클래스 유형: Entity 클래스
 */

class Account // 계좌 객체를 만드는 클래스
{
private:
	int accID; // 계좌번호 변수
	int balance; // 잔액 변수
	char* cusName; // 고객이름 변수

public:
	Account(int ID, int money, char* name); // 생성자로 ID, money, name을 받아서 초기화
	Account(const Account& ref); // 복사 생성자

	int GetAccID() const;  // accID 반환
	void Deposit(int money); //입금 함수
	int Withdraw(int money); // 출금 함수
	void ShowAccInfo() const; // 계좌정보 출력
	~Account(); // 소멸자로 cusName 메모리 해제
};

Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money) // 생성자로 ID, money을 받아서 초기화
{
	cusName = new char[strlen(name) + 1]; // name의 길이 + 1만큼 cusName에 메모리 할당
	strcpy_s(cusName, (strlen(name) + 1), name); // name을 cusName에 복사
}

Account::Account(const Account& ref) // 복사 생성자
	: accID(ref.accID), balance(ref.balance) // accID, balance를 ref의 accID, balance로 초기화
{
	cusName = new char[strlen(ref.cusName) + 1]; // ref의 cusName의 길이 + 1만큼 cusName에 메모리 할당
	strcpy_s(cusName, (strlen(ref.cusName) + 1), ref.cusName); // ref의 cusName을 cusName에 복사
}

int Account::GetAccID() const { return accID; } // accID 반환

void Account::Deposit(int money) // 입금액을 받아 잔액에 더함
{
	balance += money;
}

int Account::Withdraw(int money) // 출금액 반환, 부족 시 0 반환, 출금액만큼 현재 잔액에서 뺌
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const // 계좌정보 출력
{
	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}

Account::~Account() // 소멸자로 cusName 메모리 해제
{ 
	delete[]cusName;
}


/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: 컨트롤(Control) 클래스
 */

class AccountHandler // 계좌 객체를 관리하는 클래스
{
private:
	Account* accArr[100]; // Account 저장을 위한 배열
	int accNum; // 저장된 Account 수

public:
	AccountHandler(); // 생성자
	void ShowMenu(void) const; // 메뉴 출력
	void MakeAccount(void); // 계좌개설
	void DepositMoney(void); // 입금
	void WithdrawMoney(void); // 출금
	void ShowAllAccInfo(void) const; // 전체 계좌정보 출력
	~AccountHandler(); // 소멸자
};

void AccountHandler::ShowMenu(void) const // 메뉴 출력
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void) // 계좌개설 함수
{
	int id; // 계좌번호
	char name[NAME_LEN]; // 이름
	int balance; // 잔액

	// 계좌개설 시 필요한 정보 입력받기
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name); // Account 객체 생성 후 배열에 저장
}

void AccountHandler::DepositMoney(void) // 입금 함수
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
			cout << "입금완료" << endl << endl;
			return; // 함수 종료
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) // 출금 함수
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
				cout << "잔액부족" << endl << endl;
				return; // 함수 종료
			}

			cout << "출금완료" << endl << endl; // 출금완료 출력
			return; // 함수 종료
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl; // 계좌번호가 일치하지 않는 경우 출력
}

AccountHandler::AccountHandler() : accNum(0) // 생성자로 accNum을 0으로 초기화
{  }

void AccountHandler::ShowAllAccInfo(void) const // 전체 계좌정보 출력
{
	for (int i = 0; i < accNum; i++) // 만들어진 계좌 개수만큼 반복
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() // 만들어진 계좌 개수만큼 반복하며 메모리 해제
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


/*
 * 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
 */

int main(void)
{
	AccountHandler manager; // AccountHandler 객체 생성
	int choice; // 메뉴선택 변수

	while (1)
	{
		manager.ShowMenu(); // 메뉴 출력
		cout << "선택: ";
		cin >> choice; // 메뉴 선택
		cout << endl;

		switch (choice) // 선택에 따라 함수 동작
		{
		case MAKE: // 계좌개설
			manager.MakeAccount();
			break;
		case DEPOSIT: // 입금
			manager.DepositMoney();
			break;
		case WITHDRAW: // 출금
			manager.WithdrawMoney();
			break;
		case INQUIRE: // 전체 계좌정보 출력
			manager.ShowAllAccInfo();
			break;
		case EXIT: // 프로그램 종료
			return 0;
		default: // 잘못된 선택
			cout << "Illegal selection.." << endl;
		}
	}

	return 0; // 프로그램 종료
}