#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()
	{
		cout << "int Çüº¯È¯" << endl;
		return num;
	}
	void ShowNumber()
	{
		cout << num << endl;
	}
};


int main(void)
{
	Number num;
	num = 30;
	num.ShowNumber();

	Number num2 = num + 70;
	num2.ShowNumber();

	return 0;
}