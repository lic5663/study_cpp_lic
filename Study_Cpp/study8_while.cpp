#include <iostream>
#include <time.h>
using namespace std;

// ���������� ����ü
enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};

int main()
{
	/*
	�ݺ��� : Ư�� �۾� �ݺ� ���� ���
	���� : for, while, do while 3������ ����.
	while (���ǽ�) {} �� ����.
	*/

	int iNumber = 0;

	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;
	}

	// DOS ȯ�濡�� ȭ�� Ŭ����
	system("cls");

	srand((unsigned int)time(0));
	int iPlayer, iAI;

	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. ��" << endl;
	cout << "4. ����" << endl;

	while (true)
	{
		
		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_END)
		{
			cout << " �߸��� ���� �Է��ϼ̽��ϴ�." << endl;
			continue;
		}

		else if (iPlayer == SRP_END)
		{
			cout << " �����մϴ�." << endl;
			break;
		}

		switch (iPlayer)
		{
		case SRP_S:
			cout << "Player : ����" << endl;
			break;
		case SRP_R:
			cout << "Player : ����" << endl;
			break;
		case SRP_P:
			cout << "Player : ��" << endl;
			break;
		}

		
		// ���� ����
		iAI = rand() % 3 + SRP_S;

		switch (iAI)
		{
		case SRP_S :
			cout << "AI : ����" << endl;
			break;
		case SRP_R:
			cout << "AI : ����" << endl;
			break;
		case SRP_P:
			cout << "AI : ��" << endl;
			break;
		}

		int iWin = iPlayer - iAI;

		if (iWin == 1 || iWin == -2)
			cout << "Player �¸�" << endl;
		else if (iWin == 0)
			cout << "���" << endl;
		else
			cout << "AI �¸�" << endl;

		system("pause");
		system("cls");
	}
	
	
	return 0;
}