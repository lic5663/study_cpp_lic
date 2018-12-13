#ifndef __POINT_H__
#define __POINT_H__

class  Point
{
public:
	bool	InitMember(int xpos, int ypos);
	int		GetX() const;
	int		GetY() const;
	bool	SetX(int xpos);
	bool	SetY(int ypos);

private:
	int x;
	int y;
};

#endif // !__POINT_H__
