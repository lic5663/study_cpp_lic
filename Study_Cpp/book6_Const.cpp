#include <iostream>
using namespace std;

int main(void)
{
	int a = 5;
	int b = 7;
	const int * p1 = &a;
	int * const p2 = &a;
	//*p1 = 115;
	//a = 15;
	//p2 = &b;

	const int & ref = a;
	
	cout << ref << endl;
	*p2 = 17;
	cout << *p1 << endl;
	p1 = &b;
	cout << *p1 << endl;
}