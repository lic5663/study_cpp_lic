#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private :
	int xpos, ypos;
public :
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private :
	Point point;
	int rad;
public :
	void CricleInit(Point p, int r)
	{
		point = p;
		rad = r;
	}
	void ShowCircleInfo() const
	{
		cout << "radius : " << rad << endl;
		point.ShowPointInfo();
	}
};

class Ring
{
private: 
	Point point1, point2;
	Circle circle1, circle2;
	Circle inner, outter;
	bool ring;

public:
	void Init(int xpos1, int ypos1, int rad1, int xpos2, int ypos2, int rad2)
	{
		point1.Init(xpos1, ypos1);
		point2.Init(xpos2, ypos2);
		circle1.CricleInit(point1, rad1);
		circle2.CricleInit(point2, rad2);

		double p2p = sqrt(pow(xpos1 - xpos2, 2) + pow(ypos1 - ypos2, 2));
		
		if (p2p == 0 && rad1 == rad2)
		{
			ring = true;
			inner = circle1;
			outter = inner;
		}
		else if ((p2p + rad1) < rad2)
		{
			ring = true;
			outter = circle2;
			inner = circle1;
		}
		else if ((p2p + rad2) < rad1)
		{
			ring = true;
			outter = circle1;
			inner = circle2;
		}
		else
		{
			ring = false;
		}
		

	}

	void ShowRingInfo ()
	{
		if (ring)
		{
			cout << "Inner Circle Info ..." << endl;
			inner.ShowCircleInfo();
			cout << "Outter Cricle Info ... " << endl;
			outter.ShowCircleInfo();
		}
		else
		{
			circle1.ShowCircleInfo();
			circle2.ShowCircleInfo();
			cout << "두 원은 Ring 관계에 있지 않습니다." << endl;
		}
			
	}
};





int main(void)
{
	Ring ring;
	ring.Init(100, 100, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}