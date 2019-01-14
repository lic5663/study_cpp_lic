#include <iostream>
using namespace std;

class String
{
private:
	char* Str;
	int str_len;

public:
	// ������ : �����Ҵ�
	String(char* str)	
	{
		str_len = strlen(str);
		Str = new char[str_len + 1];	// +1 ���ؼ� ���޸� ���� ���� ������
		strcpy(Str, str);
	}
	// ��������� : ���� ���� ����
	String(const String& copy) : str_len(copy.str_len)
	{
		Str = new char[str_len + 1];	// ���⵵ +1 ����
		strcpy(Str, copy.Str);
	}
	// �Ҹ��� : �����Ҵ��Ѱ� ����
	~String()			
	{
		delete[] Str;
	}

	// + ������ �����ε�
	friend String& operator+(String& str1, String& str2);

	// << ������ �����ε�
	friend ostream& operator<<(ostream& os, String& str);

	// += ������ �����ε�
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
	// ���� ���� Ȯ��
	String str1("hello");
	cout << str1 << endl;

	// ��������� ���� �۵� Ȯ��
	String str2 = str1;
	cout << str2 << endl;

	// << �����ε� ���� �۵� Ȯ��
	cout << str1 << str2 << endl;

	// + �����ε� ���� �۵� Ȯ��
	String str3 = str1 + str2;
	cout << str3 << endl;

	
	cout << "������ �ǳ���" << endl;
	// += �����ε� ���� �۵� Ȯ��
	str1 += str2;
	cout << str1 << endl;
	
	return 0;
}