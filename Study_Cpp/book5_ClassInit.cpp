#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1, num2;
public:
	SoSimple(int n1, int n2) : num1(n1),num2(n2) {}
	SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2)
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
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1; 
	cout << "���� �� �ʱ�ȭ ����" << endl << endl;
	sim1.ShowSimpleData();
	sim2.ShowSimpleData();

	return 0;
}



//SoSimple sim2(sim1);
// explicit�� ���� ������ ��ȯ�� ���Ƶ����� ��� �Ұ�