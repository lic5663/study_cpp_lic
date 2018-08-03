#include <iostream>
using namespace std;


int main(void)
{
	/*
	사칙연산자 : +, -, *, /, %
	관계연산자 : >, <, >=, <= , ==, != 
				값대 값을 연산하여 참/거짓으로 결과를 반환
	논리연산자 : 참/거짓 대 참/거짓 연산하여 참/거짓으로 결과 반환
				AND(&&) , OR (||) , NOT (!)
	A	B	AND	OR
	0	0	0	0
	1	0	0	1
	0	1	0	1
	1	1	1	1
	
	*/

	cout << "10 < 20 =" << (10 < 20) <<  endl;
	cout << "10 > 20 =" << (10 > 20) << endl;
	cout << "10 <= 20 =" << (10 <= 20) << endl;
	cout << "10 >= 20 =" << (10 >= 20) << endl;
	cout << "10 == 20 =" << (10 == 20) << endl;
	cout << "10 != 20 =" << (10 != 20) << endl;

	int number;

	cout << "숫자를 입력하라 : ";
	cin >> number;

	cout << "10 ~ 20 사이에 "<< (10 <= number && number <= 20) << endl;

	return 0;
}