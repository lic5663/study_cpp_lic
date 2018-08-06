#include <iostream>
#include <time.h>
using namespace std;

// 가위바위보 열거체
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
	반복문 : 특정 작업 반복 수행 기능
	종류 : for, while, do while 3종류가 존재.
	while (조건식) {} 의 형태.
	*/

	int iNumber = 0;

	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;
	}

	// DOS 환경에서 화면 클리어
	system("cls");

	srand((unsigned int)time(0));
	int iPlayer, iAI;

	cout << "1. 가위" << endl;
	cout << "2. 바위" << endl;
	cout << "3. 보" << endl;
	cout << "4. 종료" << endl;

	while (true)
	{
		
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_END)
		{
			cout << " 잘못된 값을 입력하셨습니다." << endl;
			continue;
		}

		else if (iPlayer == SRP_END)
		{
			cout << " 종료합니다." << endl;
			break;
		}

		switch (iPlayer)
		{
		case SRP_S:
			cout << "Player : 가위" << endl;
			break;
		case SRP_R:
			cout << "Player : 바위" << endl;
			break;
		case SRP_P:
			cout << "Player : 보" << endl;
			break;
		}

		
		// 봇이 선택
		iAI = rand() % 3 + SRP_S;

		switch (iAI)
		{
		case SRP_S :
			cout << "AI : 가위" << endl;
			break;
		case SRP_R:
			cout << "AI : 바위" << endl;
			break;
		case SRP_P:
			cout << "AI : 보" << endl;
			break;
		}

		int iWin = iPlayer - iAI;

		if (iWin == 1 || iWin == -2)
			cout << "Player 승리" << endl;
		else if (iWin == 0)
			cout << "비김" << endl;
		else
			cout << "AI 승리" << endl;

		system("pause");
		system("cls");
	}
	
	
	return 0;
}