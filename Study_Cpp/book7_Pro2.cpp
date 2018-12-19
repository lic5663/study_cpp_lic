#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char *name;
	int age;
public:
	MyFriendInfo(char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~MyFriendInfo()
	{
		delete[] name;
	}
	void ShowMyFriendInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char* myname, int myage, char* myaddr, char* myphone) : MyFriendInfo(myname,myage)
	{
		addr = new char[strlen(myaddr) + 1];
		strcpy(addr, myaddr);

		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}
	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;

	}
	void ShowMyFriendDetailInfo() const
	{
		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}
};

int main(void)
{
	MyFriendDetailInfo mfdi1("kim", 23, "대구시", "010-1234-4567");
	mfdi1.ShowMyFriendDetailInfo();

	MyFriendDetailInfo mfdi2("lee", 27, "서울시", "010-9876-4184");
	mfdi2.ShowMyFriendDetailInfo();

	return 0;
}