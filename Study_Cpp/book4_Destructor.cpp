#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 :" << name << endl;
		cout << "나이 :" << age << endl;
	}
	~Person()
	{
		delete []name;
		cout << "called Destructor!" << endl;
	}

private:
	char*	name;
	int		age;

};

int main(void)
{
	Person man1("Lee In Chan", 27);
	Person man2("Lee Sin", 37);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	cout << "TEEEEEEEEEEEEEST" << endl;


	return 0;
}