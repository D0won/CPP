#include<iostream>
#include<string>
using namespace std;
void P8(); // 8번 문제
void P9(); // 9번 문제
void P13(); // 13번 문제
int main(void)
{
	P8();
	P9();
	P13();
	return 0;
	
}

void P8()
{
	string text; //문자열을 받는 string 객체
	int alp = 0, num = 0, nul = 0; // 알파벳 개수:alp,숫자 개수:num,공백 개수:nul
	getline(cin, text); // 문자열 받기
	int len = text.length(); // 문자열의 길이 받기
	for (int i = 0; i < len; i++)
	{
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
			alp++; // 알파벳 찾을 때마다 1추가
		if (text[i] >= '1' && text[i] <= '9')
			num++; // 숫자 찾을 때마다 1추가
		if (text[i] == ' ')
			nul++; // 공백 찾을 때마다 1추가
	}
	cout << "알파벳 개수:" << alp << ",숫자 개수:" << num << ",공백 개수:" << nul << endl;
}

void P9()
{
	string text; //문자열 받는 string 객채
	int nul = 0; // 공백 문자의 개수 저장
	getline(cin, text); //문자열 받기
	int len = text.length(); // 문자열의 길이 받기
	for (int i = 0; i < len; i++)
	{
		if (text[i] == ' ') // 공백이 있을 떄 마다 하나씩 추가
			nul++;
	}
	cout << "단어의개수:" << nul + 1 << endl; // 공백에 +1한 값이 문자의 개수가 된다.
}

void P13()
{
	string text1; // 일반 텍스트
	string text2; // 찾는 문자 받기
	string text3; // 바꿀 문자 받기
	cout << "텍스트를 입력하시오: ";
	getline(cin, text1);
	cout << "찾는 문자를 입력하시오: ";
	getline(cin, text2);
	int rep = text1.find(text2); // 해당 단어의 첫번째 index 찾기
	cout << "바꿀 문자를 입력하시오: ";
	getline(cin, text3);
	int len = text3.length(); // 해당 단어의 길이 받기
	text1.replace(rep, len, text3); // 찾은 단어를 바꿀 단어로 바꾸기
	cout <<"텍스트가 바뀌었습니다."<<endl<<text1 << endl;
}