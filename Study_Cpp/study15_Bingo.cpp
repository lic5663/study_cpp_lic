#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
using namespace std;
// ���� ����
bool bGameover = false;
bool bWin = false;
int iCount = 1;
int horizontalLine = 0, verticlaLine = 0, diagonalLine = 0;

int iHor = 0x00000000;
int iVer = 0x00000000;
int iDia = 0x00000000;

const int H1 = 0x00000001;			//	1
const int H2 = 0x00000002;			//	10
const int H3 = 0x00000004;			//	100
const int H4 = 0x00000008;			//	1000
const int H5 = 0x00000010;			//	10000

const int V1 = 0x00000001;			//	1
const int V2 = 0x00000002;			//	10
const int V3 = 0x00000004;			//	100
const int V4 = 0x00000008;			//	1000
const int V5 = 0x00000010;			//	10000

const int D1 = 0x00000001;			//	1
const int D2 = 0x00000002;			//	10


// �� ���� ����ü
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
// ���ڻ� ���� �Լ�
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
// �� �⺻ ���� �Լ�
void CreatePlate(int *iNumber)
{
	// �⺻�� ����
	for (int i = 0; i < 25; i++)
		iNumber[i] = i + 1;

	// ����
	int idx1, idx2, iTemp;
	srand((unsigned int)time(0));

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
}
// ȭ�� ��� �Լ�
void Display(int *iNumber, int iBingoLine)
{
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (iNumber[i * 5 + j] == INT_MAX)
			{
				if (((int)pow(2,j) & iVer) || ((int)pow(2, i) & iHor))
				{
					setcolor(GREEN, BLACK);
					cout << "*\t";
					setcolor(DARK_GRAY, BLACK);
				}
				else if (i == j)
				{
					if (iDia & D1)
					{
						setcolor(GREEN, BLACK);
						cout << "*\t";
						setcolor(DARK_GRAY, BLACK);
					}
					else if ((i + j) == 4)
					{
						if (iDia & D2)
						{
							setcolor(GREEN, BLACK);
							cout << "*\t";
							setcolor(DARK_GRAY, BLACK);
						}
						else
						{
							setcolor(RED, BLACK);
							cout << "*\t";
							setcolor(DARK_GRAY, BLACK);
						}
					}
					else
					{
						setcolor(RED, BLACK);
						cout << "*\t";
						setcolor(DARK_GRAY, BLACK);
					}
				}
				else if ((i + j) == 4)
				{
					if (iDia & D2)
					{
						setcolor(GREEN, BLACK);
						cout << "*\t";
						setcolor(DARK_GRAY, BLACK);
					}
					else
					{
						setcolor(RED, BLACK);
						cout << "*\t";
						setcolor(DARK_GRAY, BLACK);
					}
				}
				else
				{
					setcolor(RED, BLACK);
					cout << "*\t";
					setcolor(DARK_GRAY, BLACK);
				}
			}
			else
				cout << iNumber[i * 5 + j] << "\t";
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
	cout << "���� : " << horizontalLine << " ���� : " << verticlaLine << " �밢�� : " << diagonalLine  <<endl;
	
	cout << iCount << "ȸ�� | �����: " << iBingoLine;
	if (bWin)
	{
		cout << "  ���ӿ� �¸��ϼ̽��ϴ�." << endl;
		bGameover = true;
	}
	else
	{
		cout << " | ���ڸ� �Է����ּ��� (���� : 0) : ";
	}
}
// Ű �Է� �Լ�
void Input(int* iNumber)
{
	int iInput;
	
	cin >> iInput;
	
	if (iInput == 0)
	{
		bGameover = true;
		cout << "������ �����մϴ�." << endl;
	}
		
	else if (iInput < 0 || iInput > 25)
	{
		cout << "�������� ���Դϴ�." << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iNumber[i])
			{
				iNumber[i] = INT_MAX;
				iCount++;
				break;
			}
			else if (i == 24)
			{
				cout << "�̹� üũ�� ���Դϴ�." << endl;
				system("pause");
			}
		}
	}
}
// ���� üũ �Լ�
int lineCheck(int* iNumber)
{
	horizontalLine = 0, verticlaLine = 0, diagonalLine = 0;
	// ���� ���� üũ
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (iNumber[i * 5 + j] != INT_MAX)
				break;
			else if (j == 4 && iNumber[i * 5 + j] == INT_MAX)
			{
				horizontalLine++;
				iHor = iHor | (int)pow(2, i);
			}
				
		}
	}

	// ���� ���� üũ
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (iNumber[i * 5 + j] != INT_MAX)
				break;
			else if (i == 4 && iNumber[i * 5 + j] == INT_MAX)
			{
				iVer = iVer | (int)pow(2, j);
				verticlaLine++;
			}
		}
	}

	// �밢�� ���� üũ
	for (int i = 0; i < 25; i+=6)
	{
		if (iNumber[i] != INT_MAX)
			break;
		else if (i == 24 && iNumber[i] == INT_MAX)
		{
			iDia = iDia | 1;
			diagonalLine++;
		}
	}
	for (int i = 4; i < 21; i += 4)
	{
		if (iNumber[i] != INT_MAX)
			break;
		else if (i == 20 && iNumber[i] == INT_MAX)
		{
			iDia = iDia | 2;
			diagonalLine++;
		}
	}
	int itotalLine = horizontalLine + verticlaLine + diagonalLine;


	if (itotalLine >= 5)
		bWin = true;
	return itotalLine;
}


int main()
{
	int iNumber[25] = {};
	int iBingoLine = 0;
	// ���̽� �� ����
	CreatePlate(iNumber);
	Display(iNumber, iBingoLine);

	while (!bGameover)
	{
		// Ű �Է� �Լ�
		Input(iNumber);
		// ���� ���� üũ �Լ�
		iBingoLine = lineCheck(iNumber);
		// ȭ�� ��� �Լ�
		Display(iNumber, iBingoLine);
		
	}
	cout << endl;
	cout << "���� ����" << endl;


	return 0;
}