#include <iostream>
#include <Windows.h>
#include <time.h>
#define COLOR(b,f)    (WORD)( (((b) << 4) & 0xF0) | ((f) & 0x0F) )
#define LOTTO_NUM 7
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

	cout << "로또 번호를 입력해 주세요" << endl;

	while (true)
	{
		cin >> iMyNumber;
		
		

		for (int i = 0; i < LOTTO_NUM; i++)
		{
			if (iMyNumber > 45)
			{
				cout << "45보다 큰 숫자입니다!" << endl;
				break;
			}
			else if (iMyNumber < 1)
			{
				cout << "1보다 적은 값입니다!" << endl;
				break;
			}
			else if (iMyLotto_N[i] == iMyNumber)
			{
				cout << "중복된 숫자입니다!" << endl;
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
	cout << "내 숫자\t: ";
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
	cout << "당첨된 숫자 수 : " << winNumber << endl;
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
	// 로또 숫자 기입
	int iMy_Lotto[LOTTO_NUM] = {};
	Write_Lotto(iMy_Lotto);

	cout << endl;

	// 로또 숫자 부여
	int iLotto_Number[LOTTO_NUM] = {};
	Generator(iLotto_Number);

	cout << endl;
	cout << endl;

	// 당첨 여부 판단
	WinCheck(iMy_Lotto, iLotto_Number);
	cout << endl;
	cout << endl;
	return 0;
}

