#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;
	cout << "몫 : " << num1 / num2 << endl;
	cout << "나머지 : " << num1%num2 << endl;
}


int main(void)
{
	int num1, num2;
	cout << "두 숫자 입력 : ";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2);
		cout << "나눗셈 종료" << endl;
	}
	catch (int expn)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램 재실행 필요" << endl;
	}

	return 0;
}