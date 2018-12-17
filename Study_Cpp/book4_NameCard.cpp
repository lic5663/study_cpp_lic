#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum
	{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};

	void ShowPositionInfo(int position)
	{
		switch (position)
		{
		case COMP_POS::CLERK:
			cout << "���" << endl;
			break;
		case COMP_POS::SENIOR:
			cout << "����" << endl;
			break;
		case COMP_POS::ASSIST:
			cout << "�븮" << endl;
			break;
		case COMP_POS::MANAGER:
			cout << "����" << endl;
			break;

		default:
			break;
		}
	}
}


class NameCard
{
private:
	char*	name;
	char*	Bname;
	char*	callNumber;
	int		position;

public:
	NameCard(char* myname, char* myBname, char* mycallNum, int myposition)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);

		len = strlen(myBname) + 1;
		Bname = new char[len];
		strcpy(Bname, myBname);

		len = strlen(mycallNum) + 1;
		callNumber = new char[len];
		strcpy(callNumber, mycallNum);

		position = myposition;
	}
	// deep copy constructor
	NameCard(const NameCard& copy) : position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

		Bname = new char[strlen(copy.Bname) + 1];
		strcpy(Bname, copy.Bname);

		callNumber = new char[strlen(copy.callNumber) + 1];
		strcpy(callNumber, copy.callNumber);
	}

	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << Bname << endl;
		cout << "��ȭ��ȣ: " << callNumber << endl;
		cout << "����: ";
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}

	~NameCard()
	{
		cout << this->name << "�� �Ҹ��� �۵�" << endl;
		delete[]name;
		delete[]Bname;
		delete[]callNumber;
	}
	
};


int main(void)
{
	NameCard manClerk ("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	NameCard copy1 = manClerk;
	NameCard copy2 = manSENIOR;

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	cout << "--- copy ---" << endl;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}