#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPoint() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}
	friend Point& operator*(int times, Point &ref);
};

// 교환법칙 성립을 위한 연산자 오버로딩
Point& operator*(int times, Point &ref)
{
	return ref*times;
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 15;
	cpy.ShowPoint();

	cpy = 3 * pos;
	cpy.ShowPoint();

	return 0;
}