#include <iostream>
#include <time.h>
#include <conio.h>
//conio.h : �ܼ������ ���� �Լ� ������� 
#include <Windows.h>
using namespace std;
enum {
	BLACK,          //  0 : 000000 0000 ���
	DARK_BLUE,      //  1 : 000080 0001 ��ο� �Ķ�
	DARK_GREEN,     //  2 : 008000 0010 ��ο� �ʷ�
	DARK_SKY_BLUE,  //  3 : 008080 0011 ��ο� �ϴ�
	DARK_RED,       //  4 : 800000 0100 ��ο� ����
	DARK_VIOLET,    //  5 : 800080 0101 ��ο� ����
	DARK_YELLOW,    //  6 : 808000 0110 ��ο� ���
	DARK_GRAY,      //  7 : 808080 0111 ��ο� ȸ��
	GRAY,           //  8 : C0C0C0 1000 ȸ��
	BLUE,           //  9 : 0000FF 1001 �Ķ�
	GREEN,          // 10 : 00FF00 1010 �ʷ�
	SKY_BLUE,       // 11 : 00FFFF 1011 �ϴ�
	RED,            // 12 : FF0000 1100 ����
	VIOLET,         // 13 : FF00FF 1101 ����
	YELLOW,         // 14 : FFFF00 1110 ���
	WHITE,          // 15 : FFFFFF 1111 �Ͼ�
};
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
int main()
{
	// 1~24���� ���� 5*5
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
		iNumber[i] = i + 1;
	// ������ĭ�� ����. Ư���� �� ��� ����
	// INT_MAX : (�⺻���� ���ǵ� ����) 
	// int�� ǥ���� �� �ִ� �ִ밪.
	iNumber[24] = INT_MAX;
	// Ŭ���ϰ� F12Ű�� ������ ����� �� �� �ִ�.

	// ������ ���� �����ϰ� ����
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
		// i ������
		for (int i = 0; i < 5; i++)
		{
			// j ������
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
				// �ٹ�ȣ * ���ΰ��� + ĭ��ȣ
			}
			cout << endl;
		}

		bool bWin = true;

		// ���� �Ϸ� üũ
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
			cout << " ���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ����";
		// _getch() : ���� 1���� �Է¹޴� �Լ�
		// ���� ���� �ﰢ������ �����Ѵ�.
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