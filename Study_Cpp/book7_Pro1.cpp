#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int n) : gasolineGauge(n) {}
	int GetGasGauge() const
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int ele) : Car(gas), electricGauge(ele) {}
	int GetElecGauge() const
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int WaterGauge;
public:
	HybridWaterCar(int gas, int ele , int water) : HybridCar(gas, ele) , WaterGauge(water) {}
	void ShowCurrentGauge() const
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << WaterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar wc1(75, 95, 85);
	wc1.ShowCurrentGauge();

	return 0;
}