#include <iostream>
using namespace std;
#define line_plus 5
#define line_minus 5
#define line_top  4
#define line_dia  4
#define gugu_line 6

int main()
{
	int i, j ,k;

	cout << "1. 순차적 증가" << endl;
	for (i = 0; i < line_plus; i++)
	{
		for (j = 0; j <= i; j++)
			cout << "*";
		
		cout << endl;
	}

	cout << "2. 순차적 감소" << endl;
	for (i = line_minus; i > 0; i--)
	{
		for (j = 0; j < i; j++)
			cout << "*";
		cout << endl;
	}

	cout << "3. 탑 "<<endl;
	for (i = 0; i < line_top; i++)
	{
		for (j = (line_top-i); j > 1 ; j--)
		{
			cout << " ";
		}
		for (k = 0; k < ((i*2)+1); k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "4. 다이아 " << endl;
	int iLine = 7;
	int iCount = 0;

	for (i = 0; i < iLine; ++i)
	{
		if (i > iLine / 2)
			iCount = iLine - 1 - i;
		else 
			iCount = i;
		
		for (j = 0; j < 3 - iCount; ++j)
		{
			cout << " ";
		}

		for (j = 0; j < iCount * 2 + 1; ++j)
			cout << "*";

		cout << endl;
	}

	/*
	for (i = 0; i < (line_dia * 2 - 1); i++)
	{
		if (i < line_dia)
		{
			for (j = (line_dia - i); j > 1; j--)
				cout << " ";
			
			for (k = 0; k < (i * 2 + 1); k++)
				cout << "*";
		}
		else
		{
			for (j = 0; j <= (i - line_dia); j++)
				cout << " ";
			for (k = 0; k < (2*line_dia-(i+1))*2-1 ; k++)
				cout << "*";
		}
		cout << endl;
	}
	*/
	
	cout << "5. 구구단 " << endl;
	for (i = 1; i < 10; i +=gugu_line)
	{
		for (k = 0; k < gugu_line; k++)
		{
			cout << i + k << "단\t";
		}
		cout << endl;
		for (j = 1; j < 10; j++)
		{
			for (k = 0; k < gugu_line; k++)
			{
				cout << i + k << "X" << j << "=" << (i + k)*j;
				cout << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}