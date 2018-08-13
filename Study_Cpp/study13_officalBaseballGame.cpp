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
		cout << iGameCount << "회" << endl;
		cout << "1 ~ 9 사이의 숫자중 숫자 3개를 입력하세요(0 : 종료) :";
		
		// 예외처리
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "범위 밖 숫자 입력" << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0])
		{
			cout << "중복값 입력" << endl;
			continue;
		}

		// 정답과 기입 비교
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

		// 결과 출력
		if (iStrike == 3)
		{
			cout << "정답은 [ " << iNumber[0] << iNumber[1] << iNumber[2] << " ] 입니다. " << endl;
			cout << "숫자를 모두 맞췄습니다." << endl;
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

	cout << "게임 종료" << endl;
	return 0;
}