#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	cout << endl;
	for (int i = 1; i < 10; i++)
	{
		cout << 2 * i << endl;
	}
	cout << endl;

	for (int i = 1; i <= 100; ++i)
	{
		if ((i % 2) == 0)
			cout << i << " ";
	}

	cout << endl;

	for (int i = 2; i <= 100; i +=2 )
	{
		cout << i << " ";
	}

	cout << endl;

	for (int i = 1; i <= 100; ++i)
	{
		if ((i % 7) == 0 && (i % 3) == 0)
			cout << i << " ";
	}
	cout << endl;
	int count =0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "i =" << i << " j =  " << j << " count = " << count <<endl;
			count++;
		}
	}
	return 0;
}