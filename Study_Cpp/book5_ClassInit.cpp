#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1, num2;
public:
	SoSimple(int n1, int n2) : num1(n1),num2(n2) {}
	explicit SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "Called Sosimple(Sosimple &copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	// Sosimple sim2 = sim1; // explicit로 인해 묵시적 변환을 막아둠으로 사용 불가
	SoSimple sim2(sim1);
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();

	return 0;
}