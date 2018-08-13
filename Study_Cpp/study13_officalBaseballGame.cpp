#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int iNumber[9] = {};

	for (int i = 0; i < 9; i++)
		iNumber[i] = i + 1;
	
	int idx1, idx2, iTemp;
	srand((unsigned int)time(0));

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << "*\t*\t*" << endl;
	//cout << iNumber[0] << iNumber[1] << iNumber[2] << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];
	int iGameCount = 1;

	
	while (true)
	{
		cout << iGameCount << "ȸ" << endl;
		cout << "1 ~ 9 ������ ������ ���� 3���� �Է��ϼ���(0 : ����) :";
		
		// ����ó��
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "���� �� ���� �Է�" << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0])
		{
			cout << "�ߺ��� �Է�" << endl;
			continue;
		}

		// ����� ���� ��
		iStrike = iBall = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; j++)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
						++iStrike;

					else
						++iBall;

					break;
				}
			}
		}

		// ��� ���
		if (iStrike == 3)
		{
			cout << "������ [ " << iNumber[0] << iNumber[1] << iNumber[2] << " ] �Դϴ�. " << endl;
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0)
			cout << "Out" << endl;
		else
			cout << iStrike << " Strike " << iBall << " Ball" << endl;

		++iGameCount;
	}
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "���� ����" << endl;
	return 0;
}