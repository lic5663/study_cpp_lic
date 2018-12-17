#include <iostream>
using namespace std;

class Sosimple
{
private :
	int num;
public :
	Sosimple(int n) : num(n)
	{
		cout << "New Object : " << this << endl;
	}
	Sosimple(const Sosimple& copy) : num(copy.num)
	{
		cout << "New Copy obj: " << this << endl;
	}
	~Sosimple()
	{
		cout << "Destroy obj: " << this << endl;
	}
};

Sosimple SimpleFuncObj(Sosimple ob)
{
	cout << "Parm ADR : " << &ob << endl;
	return ob;
}


int main(void)
{
	Sosimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	Sosimple tempRef = SimpleFuncObj(obj);
	cout << "Return Obj " << &tempRef << endl << endl;

	return 0;
}