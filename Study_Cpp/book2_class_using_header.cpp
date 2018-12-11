#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

void Car::InitMember(char *ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재속도 : " << curSpeed << "km/h" << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
	{
		cout << "연료 잔량 0% 가속 불가" << endl;
		return;
	}
	else
	{
		cout << "가속" << endl;
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		cout << "한계속도 도달" << endl;
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed <= CAR_CONST::BRK_STEP)
	{
		cout << "정지" << endl;
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}
