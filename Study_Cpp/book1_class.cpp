#include <iostream>
using namespace std;

namespace CAR_CONST
{
	enum 
	{
		ID_LEN =20,
		MAX_SPD = 200,
		FUEL_STEP=2,
		ACC_STEP=10,
		BRK_STEP=10
	};
}

class Car
{
public:
	void InitMembers(char *ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();

private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
};

void Car::InitMembers(char *ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자 ID :" << gamerID << endl;
	cout << "연료량 :" << fuelGauge << "%" << endl;
	cout << "현재속도 :" << curSpeed << "km/h" << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
	{
		cout << "연료가 부족합니다" << endl;
		return;
	}
	else
	{
		cout << "가속" << endl;
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}
	
	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		cout << "정지" << endl;
		curSpeed = 0;
		return;
	}
	cout << "감속" << endl;
	curSpeed -= CAR_CONST::BRK_STEP;

}

int main(void)
{
	Car run99;
	run99.InitMembers("run99",100);
	run99.ShowCarState();
	run99.Accel();
	run99.ShowCarState();
	run99.Accel();
	run99.ShowCarState();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.Break();
	run99.ShowCarState();
	run99.Break();
	run99.Break();
	run99.ShowCarState();

	return 0;
}
