#ifndef __RECTANGLE_H__
#define __RECTANGEL_H__

#include "Point.h"

class Rectangle
{
public:
	bool InitMembers(const Point &ul, const Point &lr);
	void ShowRecInfo() const;
	
private:
	Point upLeft;
	Point lowRight;

};
#endif // !__RECTANGLE_H__

