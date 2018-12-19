#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(char *myname, int myage) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
	
};

class UnivStudent : public Person
{
private :
	char major[50];
public :
	UnivStudent(char* myname, int myage, char* mymajor) : Person(myname, myage)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent ustd1("lee", 22, "Computer eng. ");
	ustd1.WhoAreYou();

	UnivStudent ustd2("kim", 26, "Electric man");
	ustd2.WhoAreYou();

	return 0;
}