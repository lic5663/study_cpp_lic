#include <iostream>
#include <Windows.h>
#include <time.h>
#define COLOR(b,f)    (WORD)( (((b) << 4) & 0xF0) | ((f) & 0x0F) )
#define LOTTO_NUM 7
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
void NumberSort(int *arr,int n)
{
	int min;
	int itemp, index;
	for (int i = 0; i < n; i++)
	{
		min = arr[i];
		index = i;
		for (int j = i; j < n; j++)
		{
			itemp = *(arr + j);
			if (itemp < min)
			{
				min = itemp;
				index = j;
			}
		}
		itemp = arr[index];
		arr[index] = arr[i];
		arr[i] = itemp;
	}

}
void Write_Lotto(int iMyLotto_N[LOTTO_NUM])
{
	int iMyNumber;
	int	index =0;

	cout << "�ζ� ��ȣ�� �Է��� �ּ���" << endl;

	while (true)
	{
		cin >> iMyNumber;
		
		

		for (int i = 0; i < LOTTO_NUM; i++)
		{
			if (iMyNumber > 45)
			{
				cout << "45���� ū �����Դϴ�!" << endl;
				break;
			}
			else if (iMyNumber < 1)
			{
				cout << "1���� ���� ���Դϴ�!" << endl;
				break;
			}
			else if (iMyLotto_N[i] == iMyNumber)
			{
				cout << "�ߺ��� �����Դϴ�!" << endl;
				break;
			}
			else if (i == (LOTTO_NUM - 1))
			{
				iMyLotto_N[index] = iMyNumber;
				index++;
			}
		}
		if (index == LOTTO_NUM)
			break;
	}
	NumberSort(iMyLotto_N,LOTTO_NUM);
	cout << "�� ����\t: ";
	for (int i = 0; i < LOTTO_NUM; i++)
		cout << iMyLotto_N[i] << "\t";
	cout << endl;
}
void Generator(int iLotto_N[LOTTO_NUM])
{
	srand((unsigned int)time(0));
	int iNumber;
	int index = 0;
	while (true)
	{
		iNumber = rand() % 45 +1;

		for (int i = 0; i < LOTTO_NUM; i++)
		{
			if (iLotto_N[i] == iNumber)
				break;
			else if (i == (LOTTO_NUM-1))
			{
				iLotto_N[index] = iNumber;
				index++;
			}
		}
		if (index == LOTTO_NUM)
			break;
	}
	NumberSort(iLotto_N,LOTTO_NUM-1);
	cout << "LOTTO\t: ";
	for (int i = 0; i < LOTTO_NUM; i++)
	{
		if (i == (LOTTO_NUM - 1))
		{
			setcolor(YELLOW, BLACK);
			cout << iLotto_N[i] << endl ;
			setcolor(WHITE, BLACK);
			break;
		}
		cout << iLotto_N[i] << "\t";
	}
		
}
void WinCheck(int* myLotto, int* Lotto)
{
	int indexArr[LOTTO_NUM] = {};
	int winNumber=0;
	for (int i = 0; i < LOTTO_NUM; i++)
	{
		for (int j = 0; j < LOTTO_NUM; j++)
		{
			if (Lotto[i] == myLotto[j])
			{
				indexArr[i] = j;
				winNumber++;
				break;
			}
		}
	}
	cout << "��÷�� ���� �� : " << winNumber << endl;
	for (int i = 0; i < LOTTO_NUM; i++)
	{
		for (int j = 0; j < winNumber; j++)
		{
			if (indexArr[j] == i)
			{
				setcolor(RED, BLACK);
			}
		}
		cout << myLotto[i] << " ";
		setcolor(WHITE, BLACK);
	}
}

int main()
{
	// �ζ� ���� ����
	int iMy_Lotto[LOTTO_NUM] = {};
	Write_Lotto(iMy_Lotto);

	cout << endl;

	// �ζ� ���� �ο�
	int iLotto_Number[LOTTO_NUM] = {};
	Generator(iLotto_Number);

	cout << endl;
	cout << endl;

	// ��÷ ���� �Ǵ�
	WinCheck(iMy_Lotto, iLotto_Number);
	cout << endl;
	cout << endl;
	return 0;
}

