#include <iostream>
#include <time.h>
#define ANS_N 3
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iBaseballArr[9] = {};

	// 기본 배열 형성.
	for (int i = 0; i < 9; i++)
		iBaseballArr[i] = i + 1;

	int idx1, idx2, iTemp;

	// Swap을 이용한 배열 셔플
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		// 정상 난수 발생 확인용 코드
		//cout << "idx1: " << idx1 << " \tidx2: " << idx2 << endl;

		iTemp = iBaseballArr[idx1];
		iBaseballArr[idx1] = iBaseballArr[idx2];
		iBaseballArr[idx2] = iTemp;
	}
	// 셔플 정상 출력용 확인용 코드
	/*
	for (int i = 0; i < 9; i++)
	{
		cout << iBaseballArr[i] << " ";
	}
	cout << endl;
	*/

	// 정답 배열 구성
	int iNumberArr[ANS_N] = {};
	for (int i = 0; i < ANS_N; i++)
	{
		iNumberArr[i] = iBaseballArr[i];
		// 정답 확인용 코드
		//cout << iNumberArr[i] << " ";
	}
	//cout << endl;
	
	// 화면 구성
	cout << "*\t*\t*" << endl;
	cout << "정답을 입력해주세요." << endl;

	// 정답 찾기
	int iAnswer[ANS_N] = {};
	bool iError = false;
	while (true)
	{
		cin >> iAnswer[0] >> iAnswer[1] >> iAnswer[2];

		// 정상값 기입 확인
		if (iAnswer[0] == 0 || iAnswer[1] == 0 || iAnswer[2] == 0)
			break;
		else if (iAnswer[0] < 0 || iAnswer[0]>9 || iAnswer[1] < 0 || iAnswer[1]>9 || iAnswer[2] < 0 || iAnswer[2]>9)
		{
			cout << "잘못된 숫자값 입력" << endl;
			iError = true;
		}
		else if (iAnswer[0] == iAnswer[1] || iAnswer[1] == iAnswer[2] || iAnswer[2] == iAnswer[0])
		{
			cout << "중복값 기입" << endl;
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
				cout << "정답은 [ " << iNumberArr[0] << iNumberArr[1] << iNumberArr[2] << " ] 입니다" << endl;
				cout << endl;
				cout << "승리하셨습니다" << endl;
				break;
			}
		}
	}
	cout << "게임을 종료합니다." << endl;
	return 0;
}