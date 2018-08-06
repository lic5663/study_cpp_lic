#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	// ���� �߻�
	srand((unsigned int)time(0));	// srand : ���� ���̺� �ۼ�
	// srand�� ������ ������� c++ 11���� ��밡���� random�� include �ϰų�
	// ���� �߻��⸦ ��ü �����ؼ� ����Ѵ�.

	cout << rand() << endl;					// ������ ����
	cout << (rand() % 100 + 100) << endl;	// 100~200 ����
	cout << rand()%10000 / 100.f << endl;	// 0~99.99 ����

	while (1)
	{

		int iUpgrade = 0;
		cout << "Upgrade �⺻ ��ġ�� �Է��Ͻÿ� : ";
		cin >> iUpgrade;

		// ��ȭ Ȯ���� ���Ѵ�.
		float fPercent = rand() % 10000 / 100.f;

		// ��ȭ Ȯ�� : ���׷��̵� 0~3 : 100%, 4~6 : 40%, 7~9: 10%
		// 10~13 : 1% , 14~15 : 0.01%
		cout << "Upgrade : " << iUpgrade << endl;
		cout << "Percent : " << fPercent << endl;

		if (iUpgrade <= 3)
			cout << "��ȭ ����" << endl;

		else if (4 <= iUpgrade && iUpgrade <= 6)
		{
			if (fPercent < 40.f)
				cout << "��ȭ ����" << endl;
			else
				cout << "��ȭ ����" << endl;
		}

		else if (7 <= iUpgrade && iUpgrade <= 9)
		{
			if (fPercent < 10.f)
				cout << "��ȭ ����" << endl;
			else
				cout << "��ȭ ����" << endl;
		}

		else if (10 <= iUpgrade && iUpgrade <= 13)
		{
			if (fPercent < 1.f)
				cout << "��ȭ ����" << endl;
			else
				cout << "��ȭ ����" << endl;
		}

		else if (14 <= iUpgrade && iUpgrade <= 15)
		{
			if (fPercent < 0.01f)
				cout << "��ȭ ����" << endl;
			else
				cout << "��ȭ ����" << endl;
		}

		else if (16 <= iUpgrade)
		{
			cout << "��ȭ �ѵ��� �����߽��ϴ�." << endl;
		}

	}


	return 0;
}