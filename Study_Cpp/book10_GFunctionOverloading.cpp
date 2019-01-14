#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}

	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);

	Point & operator+=(const Point &pos2)
	{
		xpos += pos2.xpos;
		ypos += pos2.ypos;
		
		return *this;
	}

	Point & operator-=(const Point &pos2)
	{
		xpos -= pos2.xpos;
		ypos -= pos2.ypos;

		return *this;
	}
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
	cout << "== 연산자 오버로딩 작동" << endl;
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
	cout << "!= 연산자 오버로딩 작동" << endl;
	return !(pos1 == pos2);
}

int main(void)
{
	Point pos1(3, 4);
	pos1.ShowPosition();
	Point pos2(10, 20);
	pos2.ShowPosition();
	Point pos3 = pos1 + pos2;
	pos3.ShowPosition();
	(pos1 += pos1).ShowPosition();
	(pos2 -= pos1).ShowPosition();
	pos2.ShowPosition();
	if (pos1 == pos1)
		cout << "pos1 일치" << endl;
	if (pos1 != pos2)
		cout << "pos1, pos2 불일치" << endl;
	


	return 0;
}