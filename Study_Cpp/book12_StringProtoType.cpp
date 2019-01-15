#include <iostream>
#include <cstring>
using namespace std;
#define MAX_STR_LEN 50

class String
{
private:
	char* Str;
	int str_len;

public:
	// 기초 생성자
	String()
	{
		str_len = 0;
		Str = NULL;
	}
	// 생성자 : 동적할당
	String(char* str)	
	{
		str_len = strlen(str);
		Str = new char[str_len + 1];	// +1 안해서 힙메모리 오염 감지 오류뜸
		strcpy(Str, str);
	}
	// 복사생성자 : 깊은 복사 구현
	String(const String& copy) : str_len(copy.str_len)
	{
		Str = new char[str_len + 1];	// 여기도 +1 주의
		strcpy(Str, copy.Str);
	}
	// 소멸자 : 동적할당한거 삭제
	~String()			
	{
		delete[] Str;
	}
	// String 내부 멤버 변경
	void MemberChange(char* str)
	{
		this->str_len = strlen(str);
		this->Str = new char[this->str_len + 1];	// 여기도 +1 주의
		strcpy(this->Str, str);
	}
	// += 연산자 오버로딩
	String& operator+=(String& str)
	{
		int temp_len = this->str_len + str.str_len;
		char* temp_str;
		temp_str = new char[temp_len + 2];
		strcpy(temp_str, this->Str);
		strcat(temp_str, str.Str);

		this->str_len = temp_len + 1;
		this->Str = new char[temp_len + 2];
		strcpy(this->Str, temp_str);

		return *this;
	}
	// == 연산자 오버로딩
	bool operator==(String& str)
	{
		if (this->str_len == str.str_len)
			if (!strcmp(this->Str, str.Str))
				return true;			
		return false;
	}


	// + 연산자 오버로딩
	friend String& operator+(String& str1, String& str2);
	// << 연산자 오버로딩
	friend ostream& operator<<(ostream& os, String& str);
	friend istream& operator>>(istream& is, String& str);

};

ostream& operator<<(ostream& os,String& str)
{
	os << str.Str;
	return os;
}

istream& operator>>(istream& is, String& str)
{
	char st[MAX_STR_LEN];
	is >> st;
	str.MemberChange(st);
	return is;
}

String& operator+(String& str1, String& str2)
{
	static String strSum;
	char * charSum;
	char * st1, * st2;
	
	st1 = new char[str1.str_len + 1];
	st2 = new char[str2.str_len + 1];
	strcpy(st1, str1.Str);
	strcpy(st2, str2.Str);
	charSum = strcat(st1, st2);
	strSum.MemberChange(charSum);
	
	return strSum;
}

int main(void)
{
	// 정상 생성 확인
	String str1("hello");
	cout << "str1 : " << str1 << endl;

	// 복사생성자 정상 작동 확인
	String str2 = str1;
	cout << "str2 : " << str2 << endl;

	// + 오버로딩 정상 작동 확인
	String str3 = str1 + str2;
	cout << "str3(str1 + str2) : " << str3 << endl;

	// += 오버로딩 정상 작동 확인
	str3 += str2;
	cout << "str3 : " << str3 << endl;

	String str4("muyo");
	String str5 = str4;
	// == 오버로딩 정상 작동 확인
	if (str4 == str5)
		cout << "동일 문자열입니다." << endl;
	else
		cout << "다른 문자열입니다" << endl;

	if (str3 == str5)
		cout << "동일 문자열입니다." << endl;
	else
		cout << "다른 문자열입니다" << endl;

	// >> 오버로딩 정상 작동 확인
	String str6;
	cin >> str6;
	cout << "str6 : " << str6 << endl;
	
	return 0;
}