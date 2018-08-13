#include <iostream>
#include <time.h>
#define ANS_N 3
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iBaseballArr[9] = {};

	// �⺻ �迭 ����.
	for (int i = 0; i < 9; i++)
		iBaseballArr[i] = i + 1;

	int idx1, idx2, iTemp;

	// Swap�� �̿��� �迭 ����
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		// ���� ���� �߻� Ȯ�ο� �ڵ�
		//cout << "idx1: " << idx1 << " \tidx2: " << idx2 << endl;

		iTemp = iBaseballArr[idx1];
		iBaseballArr[idx1] = iBaseballArr[idx2];
		iBaseballArr[idx2] = iTemp;
	}
	// ���� ���� ��¿� Ȯ�ο� �ڵ�
	/*
	for (int i = 0; i < 9; i++)
	{
		cout << iBaseballArr[i] << " ";
	}
	cout << endl;
	*/

	// ���� �迭 ����
	int iNumberArr[ANS_N] = {};
	for (int i = 0; i < ANS_N; i++)
	{
		iNumberArr[i] = iBaseballArr[i];
		// ���� Ȯ�ο� �ڵ�
		//cout << iNumberArr[i] << " ";
	}
	//cout << endl;
	
	// ȭ�� ����
	cout << "*\t*\t*" << endl;
	cout << "������ �Է����ּ���." << endl;

	// ���� ã��
	int iAnswer[ANS_N] = {};
	bool iError = false;
	while (true)
	{
		cin >> iAnswer[0] >> iAnswer[1] >> iAnswer[2];

		// ���� ���� Ȯ��
		if (iAnswer[0] == 0 || iAnswer[1] == 0 || iAnswer[2] == 0)
			break;
		else if (iAnswer[0] < 0 || iAnswer[0]>9 || iAnswer[1] < 0 || iAnswer[1]>9 || iAnswer[2] < 0 || iAnswer[2]>9)
		{
			cout << "�߸��� ���ڰ� �Է�" << endl;
			iError = true;
		}
		else if (iAnswer[0] == iAnswer[1] || iAnswer[1] == iAnswer[2] || iAnswer[2] == iAnswer[0])
		{
			cout << "�ߺ��� ����" << endl;
			iError = true;
		}
		else
			iError = false;

		if (!iError)
		{
			int iStrike_N = 0;
			int iBall_N = 0;

			for (int i = 0; i < ANS_N; i++)
			{
				for (int j = 0; j < ANS_N; j++)
				{
					if (iAnswer[j] == iNumberArr[i])
					{
						if (i == j)
						{
							++iStrike_N;
							break;
						}
						else
						{
							++iBall_N;
							break;
						}
					}
				}
			}
			cout << iStrike_N << " Strike\t" << iBall_N << " Ball" << endl;

			if (iStrike_N == ANS_N)
			{
				system("cls");
				cout << "������ [ " << iNumberArr[0] << iNumberArr[1] << iNumberArr[2] << " ] �Դϴ�" << endl;
				cout << endl;
				cout << "�¸��ϼ̽��ϴ�" << endl;
				break;
			}
		}
	}
	cout << "������ �����մϴ�." << endl;
	return 0;
}