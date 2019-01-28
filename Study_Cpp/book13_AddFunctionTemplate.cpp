#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Add<int>(155, 351) << endl;
	cout << Add<double>(1.7, 8.4) << endl;
	cout << Add<string>("hello", "bye") << endl;

	return 0;

}