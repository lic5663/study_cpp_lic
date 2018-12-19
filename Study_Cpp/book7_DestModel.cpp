#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char *name;
public :
	Person(char * myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~Person()
	{
		delete[]name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class Univstudent : public Person
{
private:
	char* major;
public :
	Univstudent(char* myname, char* mymajor) : Person(myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~Univstudent()
	{
		delete []major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};


int main(void)
{
	Univstudent st1("kim", "Electronic Eng");
	st1.WhoAreYou();

	Univstudent st2("lee", "Physics");
	st2.WhoAreYou();

	return 0;
}