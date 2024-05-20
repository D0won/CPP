#include<iostream>
using namespace std;

class Date
{
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d)
    {}

    void PrintDate()
    {
        cout << year << "년 " << month << "월 " << day << "일\n";
    }
};

class Employee
{
    string name;
    Date birthDate;
    Date hireDate;
public:
    Employee(string n, Date b, Date h) : name(n), birthDate(b), hireDate(h)
    {}

    void PrintEmployeeImpormation()
    {
        cout << "직원의 이름 : " << name << "\n";
        cout << "직원의 생일 : ";
        birthDate.PrintDate();
        cout << "직원의 입사일 : ";
        hireDate.PrintDate();
    }
};

int main(void)
{
    Date bir(1987, 4, 27);
    Date hir(2011, 2, 05);
    Employee emp("홍길동", bir, hir);
    emp.PrintEmployeeImpormation();
    return 0;
}