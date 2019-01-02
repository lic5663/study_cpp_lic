#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0,int y=0) :xpos(x),ypos(y)
	{}
	void ShowPoint() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPoint();

	cpy = pos * 3 * 2;
	cpy.ShowPoint();

	cpy = cpy * 6;
	cpy.ShowPoint();


	return 0;
}