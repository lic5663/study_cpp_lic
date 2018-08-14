#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

int main()
{
	
	int iNumber[25] = {};
	int iAINumber[25] = {};
	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
		
	srand((unsigned int)time(0));
	int idx1, idx2, iTemp;

	for (int i = 0; i < 100; i++)
	{
		// ���� �� ����
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI �� ����
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo =0;
	int iAIMode;
	while (true)
	{
		// AI ���̵� ����.
		system("cls");
		cout << "1.Easy" << endl;
		cout << "2.Hard" << endl;
		cout << "AI ��� ���� : ";
		
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}
	
	/*
	AI Easy ���� ���� AI�� ���ڸ���� *�� �ٲ��� ����
	���ڸ� ���� (����)
	*/

	//���þȵ� ��� �迭 ����
	int iNoneSelect[25] = {};
	// ���� �ȵ� ���� ���� ����
	int iNoneSelectCount = 0;
	int iInput = 0;
	int iAIInput = 0;

	while (true)
	{
		system("cls");

		// ���ڸ� 5x5�� ���
		cout << "=========== Player ===========" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[5 * i + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[5 * i + j] << "\t";
			}
			cout << endl;
		}
		
		cout << "Bingo Line :" << iBingo << endl << endl;

		cout << "===========   AI   ===========" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iAINumber[5 * i + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[5 * i + j] << "\t";
			}
			cout << endl;
		}

		cout << "AIBingo Line :" << iAIBingo << endl << endl;

		// ������ 5 �̻��� ��� ������ ����
		if (iBingo >= 5)
		{
			cout << "Player �¸�" << endl;
			break;
		}
		else if (iAIBingo >=5)
		{
			cout << "AI �¸�" << endl;
			break;
		}
		
		cout << "Pl : " << iInput << endl;
		cout << "AI : " << iAIInput << endl;
		cout << "���ڸ� �Է��ϼ���(0: ����)";


		// �Է�
		
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25)
			continue;

		// �ߺ� üũ �÷���
		bool bAcc = true;

		for (int i = 0; i < 25; i++)
		{
			if (iInput == iNumber[i])
			{
				// bAcc = false : �ߺ��� �ƴѰ��.
				bAcc = false;

				iNumber[i] = INT_MAX;
				break;
			}
		}
		
		if (bAcc)
			continue;

		// AI ���� ����
		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				--iNoneSelectCount;
				break;
			}
		}

		// ���� �� �� üũ
		iBingo = 0;
		iAIBingo = 0;
		// AI ���� MODE�� ���� ����
		
		switch (iAIMode)
		{
		case AM_EASY:
			// ���þȵ� ���� ��� ����
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++)
			{
				if (iAINumber[i] != INT_MAX)
				{
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}
			// ���� ���� �� �������� ����
			iAIInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			break;
		default:
			break;
		}
		// AI�� ���ڸ� ���������Ƿ� �ش� ���ڵ� ������
		// ���� ��
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iAIInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}
		// AI ��
		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iAIInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// ����, ���� �� �� ����
		int iStar1 = 0 , iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; i++)
		{
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
				// ���� ���� ���� üũ

				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;

				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}
			if (iStar1 == 5)
				iBingo++;
			if (iStar2 == 5)
				iBingo++;
			if (iAIStar1 == 5)
				iAIBingo++;
			if (iAIStar2 == 5)
				iAIBingo++;
		}

		// ���� ��� -> ���� �ϴ� �밢�� üũ
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		if (iAIStar1 == 5)
			++iAIBingo;

		// ���� ��� -> ���� �ϴ� �밢�� üũ
		iStar2 = 0;
		iAIStar2 = 0;
		for (int i = 4; i < 21; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar2;
			if (iAINumber[i] == INT_MAX)
				++iAIStar2;
		}
		if (iStar2 == 5)
			++iBingo;
		if (iAIStar2 == 5)
			++iAIBingo;
	}

	return 0;
}