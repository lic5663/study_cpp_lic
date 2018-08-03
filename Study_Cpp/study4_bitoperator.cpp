#include <iostream>
using namespace std;
void binary_change(int number);

int main(void)
{
	int number;
	/*
	진수 : 2진수, 8진수, 10진수, 16진수
	2진수	: 0 ~ 1
	8진수	: 0 ~ 7
	10진수	: 0 ~ 9
	16진수	: 0 ~ 15 -> 0 ~ f

	진수들은 상호 변환이 가능하다.

	비트단위 논리연산자 : 2진수 단위의 연산을 실행
	종류 : AND(&), OR(|), NOT(~), XOR(^)
	A	B	XOR
	0	0	0
	1	0	1
	0	1	1
	1	1	0

	*/

	cout << "2진수로 변환할 수를 입력하시오" << endl;
	cin >> number;
	binary_change(number);

	return 0;
}

void binary_change(int number)
{
	int quotient =0;

	if (number == 1)
	{
		cout << number;
	}
	else
	{
		quotient = number / 2;
		binary_change(quotient);
		cout << number % 2;
	}
}