#include <iostream>
#include <time.h>
#include <conio.h>
//conio.h : 콘솔입출력 관련 함수 헤더파일 
#include <Windows.h>
using namespace std;
enum {
	BLACK,          //  0 : 000000 0000 까망
	DARK_BLUE,      //  1 : 000080 0001 어두운 파랑
	DARK_GREEN,     //  2 : 008000 0010 어두운 초록
	DARK_SKY_BLUE,  //  3 : 008080 0011 어두운 하늘
	DARK_RED,       //  4 : 800000 0100 어두운 빨강
	DARK_VIOLET,    //  5 : 800080 0101 어두운 보라
	DARK_YELLOW,    //  6 : 808000 0110 어두운 노랑
	DARK_GRAY,      //  7 : 808080 0111 어두운 회색
	GRAY,           //  8 : C0C0C0 1000 회색
	BLUE,           //  9 : 0000FF 1001 파랑
	GREEN,          // 10 : 00FF00 1010 초록
	SKY_BLUE,       // 11 : 00FFFF 1011 하늘
	RED,            // 12 : FF0000 1100 빨강
	VIOLET,         // 13 : FF00FF 1101 보라
	YELLOW,         // 14 : FFFF00 1110 노랑
	WHITE,          // 15 : FFFFFF 1111 하양
};
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
int main()
{
	// 1~24까지 숫자 5*5
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
		iNumber[i] = i + 1;
	// 마지막칸은 공백. 특수한 값 사용 예정
	// INT_MAX : (기본으로 정의된 값임) 
	// int로 표현할 수 있는 최대값.
	iNumber[24] = INT_MAX;
	// 클릭하고 F12키를 누르면 대상값을 볼 수 있다.

	// 마지막 공백 제외하고 셔플
	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iStar = 24;
	int iChange = 24;

	while (true)
	{
		// i 세로줄
		for (int i = 0; i < 5; i++)
		{
			// j 가로줄
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					setcolor(RED, BLACK);
					cout << "*\t";
					setcolor(WHITE, BLACK);
				}
				else if (i * 5 + j == iChange)
				{
					setcolor(YELLOW, BLACK);
					cout << iNumber[i * 5 + j] <<"\t";
					setcolor(WHITE, BLACK);
				}
				else if (i * 5 + j + 1 == iNumber[i * 5 + j])
				{
					setcolor(GREEN, BLACK);
					cout << iNumber[i * 5 + j] << "\t";
					setcolor(WHITE, BLACK);
				}
				else
					cout << iNumber[i * 5 + j] << "\t";
				// 줄번호 * 가로개수 + 칸번호
			}
			cout << endl;
		}

		bool bWin = true;

		// 퍼즐 완료 체크
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << " 숫자를 모두 맞췄습니다." << endl;
			break;
		}

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료";
		// _getch() : 문자 1개를 입력받는 함수
		// 엔터 없이 즉각적으로 반응한다.
		char cInput = _getch();
		cout << endl;

		if (cInput == 'q' || cInput == 'Q')
			break;
		
		switch (cInput)
		{
		case 'w':
		case 'W':
			if (iStar > 4)
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar - 5];
				iNumber[iStar - 5] = iTemp;
				iChange = iStar;
				iStar -= 5;
			}
			else
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar + 20];
				iNumber[iStar + 20] = iTemp;
				iChange = iStar;
				iStar += 20;
			}
			break;

		case 's':
		case 'S':
			if (iStar < 20)
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar + 5];
				iNumber[iStar + 5] = iTemp;
				iChange = iStar;
				iStar += 5;
			}
			else
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar - 20];
				iNumber[iStar - 20] = iTemp;
				iChange = iStar;
				iStar -= 20;
			}
			break;

		case 'a':
		case 'A':
			if (iStar%5 != 0)
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar - 1];
				iNumber[iStar - 1] = iTemp;
				iChange = iStar;
				--iStar;
			}
			else
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar + 4];
				iNumber[iStar + 4] = iTemp;
				iChange = iStar;
				iStar += 4;
			}
			break;

		case 'd':
		case 'D':
			if (iStar%5 != 4)
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar + 1];
				iNumber[iStar + 1] = iTemp;
				iChange = iStar;
				++iStar;
			}
			else
			{
				iTemp = iNumber[iStar];
				iNumber[iStar] = iNumber[iStar - 4];
				iNumber[iStar - 4] = iTemp;
				iChange = iStar;
				iStar -= 4;
			}
			break;

		default:
			break;
		}
		system("cls");
	}
	cout << endl;
	cout << "GAME OVER" << endl;
	return 0;
}