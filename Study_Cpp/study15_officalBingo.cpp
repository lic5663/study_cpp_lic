#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

// AI 추측용 열거
enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT

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
		// 유저 덱 셔플
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI 덱 셔플
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
		// AI 난이도 선택.
		system("cls");
		cout << "1.Easy" << endl;
		cout << "2.Hard" << endl;
		cout << "AI 모드 선택 : ";
		
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}
	
	/*
	AI Easy 모드는 현재 AI의 숫자목록중 *로 바뀌지 않은
	숫자를 선택 (랜덤)
	*/

	//선택안된 목록 배열 생성
	int iNoneSelect[25] = {};
	// 선택 안된 숫자 개수 저장
	int iNoneSelectCount = 0;
	int iInput = 0;
	int iAIInput = 0;

	while (true)
	{
		system("cls");

		// 숫자를 5x5로 출력
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

		// 라인이 5 이상일 경우 게임을 종료
		if (iBingo >= 5)
		{
			cout << "Player 승리" << endl;
			break;
		}
		else if (iAIBingo >=5)
		{
			cout << "AI 승리" << endl;
			break;
		}
		
		cout << "Pl : " << iInput << endl;
		cout << "AI : " << iAIInput << endl;
		cout << "숫자를 입력하세요(0: 종료)";


		// 입력
		
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25)
			continue;

		// 중복 체크 플래그
		bool bAcc = true;

		for (int i = 0; i < 25; i++)
		{
			if (iInput == iNumber[i])
			{
				// bAcc = false : 중복이 아닌경우.
				bAcc = false;

				iNumber[i] = INT_MAX;
				break;
			}
		}
		
		if (bAcc)
			continue;

		// AI 숫자 변경
		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				--iNoneSelectCount;
				break;
			}
		}

		// 빙고 줄 수 체크
		iBingo = 0;
		iAIBingo = 0;
		// AI 선택 MODE에 따라 변경
		
		switch (iAIMode)
		{
		case AM_EASY:
			// 선택안된 숫자 목록 생성
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++)
			{
				if (iAINumber[i] != INT_MAX)
				{
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}
			// 남은 숫자 중 랜덤으로 선택
			iAIInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			// 빙고 완성 가능성을 추측해 가장 높은 라인을
			// 우선적으로 부른다
			int iLine=0;
			int iStarCount=0;
			int iSaveCount=0;

			// 가로라인 별 많은 라인 구하기
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				// 별이 5개 미만( 빙고줄 아닌것)
				// 라인의 별이 가장 많은것.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i;
					iSaveCount = iStarCount;
				}
			}
			// 세로라인 별 많은 라인 구하기
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}
			// 좌->우 대각선 별 많은 라인 구하기
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			// 우->좌 대각선 별 많은 라인 구하기
			iStarCount = 0;
			for (int i = 4; i < 21; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}
			// 모든 라인 조사 완료하면 iLine이 별이 가장 많음
			// 그 줄에 있는 숫자 하나를 선택
			// 가로줄일 경우
			if (iLine <= LN_H5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iAIInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iAIInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}
			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iAIInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine == LN_RT)
			{
				for (int i = 4; i < 21; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iAIInput = iAINumber[i];
						break;
					}
				}
			}
			break;

		}
		// AI가 숫자를 선택했으므로 해당 숫자도 날린다
		// 유저 판
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iAIInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}
		// AI 판
		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iAIInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// 가로, 세로 줄 수 구함
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
				// 가로 빙고 라인 체크

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

		// 좌측 상단 -> 우측 하단 대각선 체크
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

		// 우측 상단 -> 좌측 하단 대각선 체크
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