#include <iostream>
using namespace std;

class String
{
private:
	char* Str;
	int str_len;

public:
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

	// + 연산자 오버로딩
	friend String& operator+(String& str1, String& str2);

	// << 연산자 오버로딩
	friend ostream& operator<<(ostream& os, String& str);

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
};

ostream& operator<<(ostream& os,String& str)
{
	cout << str.Str;
	return os;
}


String& operator+(String& str1, String& str2)
{
	char * charSum;
	charSum = new char[str1.str_len + str2.str_len + 2];
	charSum = strcat(str1.Str, str2.Str);
	String strSum(charSum);
	return strSum;
}

int main(void)
{
	// 정상 생성 확인
	String str1("hello");
	cout << str1 << endl;

	// 복사생성자 정상 작동 확인
	String str2 = str1;
	cout << str2 << endl;

	// << 오버로딩 정상 작동 확인
	cout << str1 << str2 << endl;

	// + 오버로딩 정상 작동 확인
	String str3 = str1 + str2;
	cout << str3 << endl;

	
	cout << "어디까지 되나요" << endl;
	// += 오버로딩 정상 작동 확인
	str1 += str2;
	cout << str1 << endl;
	
	return 0;
}