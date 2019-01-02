#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPoint() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	const Point& operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;
	}
	friend Point& operator--(Point &ref);
	friend const Point& operator--(Point &ref,int);
};

Point& operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point& operator--(Point &ref, int)
{
	const Point retobj(ref.xpos, ref.ypos);
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}

int main(void)
{
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;
	cpy.ShowPoint();
	pos.ShowPoint();

	cpy = pos++;
	cpy.ShowPoint();
	pos.ShowPoint();

	return 0;
}