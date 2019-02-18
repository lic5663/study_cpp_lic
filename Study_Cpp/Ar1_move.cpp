#include <iostream>
#include <cstring>
#include <string>
#define LINE 10
using namespace std;

class Pos
{
private:
	
	const int pos_x_limit = 5;
	const int neg_x_limit = -5;
	const int pos_y_limit = 5;
	const int neg_y_limit = -5;

public:
	int xpos, ypos;
	int tr_xpos, tr_ypos;
	Pos(int x = 0, int y = 0 ) : xpos(x),ypos(y),tr_xpos(x),tr_ypos(0){}
	bool changePos(int x, int y)
	{
		xpos += x;
		if (xpos > pos_x_limit)
		{
			xpos = pos_x_limit;
			return false;
		}
		else if (xpos < neg_x_limit)
		{
			xpos = neg_x_limit;
			return false;
		}
		else
			tr_xpos = 2 * xpos;

		ypos += y;
		if (ypos > pos_y_limit)
		{
			ypos = pos_y_limit;
			return false;
		}
		else if (ypos < neg_y_limit)
		{
			ypos = neg_y_limit;
			return false;
		}
		else
			tr_ypos = 2 * ypos;


		return true;
	}
};

int solution(string dirs)
{
	Pos pos(0, 0);
	int grid[21][21] = { 0 };
	int line = 21;
	int com = 10;

	int i = 0;
	while (dirs[i] != '\0')
	{
		switch (dirs[i])
		{
		case 'U':
			if (pos.changePos(0, 1))
			{
				grid[pos.tr_ypos + com - 1][pos.tr_xpos + com] = 1;
				
				cout << "UP" << endl;
				cout << "x :" << pos.xpos << " y :" << pos.ypos << endl;
			}
			break;
		case 'D':
			if (pos.changePos(0, -1))
			{
				grid[pos.tr_ypos + com + 1 ][pos.tr_xpos + com] = 1;
				
				cout << "Down" << endl;
				cout << "x :" << pos.xpos << " y :" << pos.ypos << endl;
			}
			break;
		case 'R':
			if (pos.changePos(1, 0))
			{
				grid[pos.tr_ypos + com][pos.tr_xpos + com - 1] = 1;
				
				cout << "Right" << endl;
				cout << "x :" << pos.xpos << " y :" << pos.ypos << endl;
			}
			break;
		case 'L':
			if (pos.changePos(-1, 0))
			{
				grid[pos.tr_ypos + com][pos.tr_xpos + com +1] = 1;
				
				cout << "Left" << endl;
				cout << "x :" << pos.xpos << " y :" << pos.ypos << endl;
			}
			break;
		default:
			break;
		}
		i++;

		for (int n = line -1 ; n > -1; --n)
		{
			for (int m = 0; m < line; m++)
			{
				cout << grid[n][m] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int answer = 0;
	cout << "Result" << endl;
	for (int n = line -1; n >-1; --n)
	{
		for (int m = 0; m < line; m++)
		{
			if (grid[n][m] == 1)
				answer++;

			cout << grid[n][m] << " ";
		}
		cout << endl;
	}
		
			

	return answer;
}

int main(void)
{
	string dirs = "LULLLLLLU";
	cout << dirs << endl;

	cout << solution(dirs) << endl;


	return 0;
}