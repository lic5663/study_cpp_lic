#include <iostream>

using namespace std;

void rec(int n)
{
	n++;
	cout << n << "번째 재귀함수 " << endl;
	if (n < 1000)
		rec(n);
}

int factorial(int number)
{
	if (number == 0)
		return 1;
	else if (number > 0)
		return number*factorial(number - 1);
}

int fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else if (n > 1)
		return fibo(n - 1) + fibo(n - 2);
}


int main()
{
	int n = 0;
	//rec(n);

	/*
	cout << "팩토리얼 수 입력 : ";
	cin >> n;
	cout << n << "! = " << factorial(n) << endl;
	*/

	cout << "피보나치 수 입력 : ";
	cin >> n;
	for (int i = 1; i < n; i++)
		cout << fibo(i) << " ";

	return 0;
}