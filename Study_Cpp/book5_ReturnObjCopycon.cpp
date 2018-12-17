#include <iostream>
using namespace std;

class Sosimple
{
private:
	int num;
public :
	Sosimple(int n) : num(n) {}
	Sosimple(const Sosimple& copy) : num(copy.num)
	{
		cout << "Called Sosimple(const Sosimple& copy)" << endl;
	}
	Sosimple& AddNum(int n)
	{
		num += n;
		cout << "AddNum 반환 전" << endl;
		return *this;
	}
	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

Sosimple SimpleFuncObj(Sosimple ob)
{
	cout << "return 이전" << endl;
	return ob;
}

int main(void)
{
	Sosimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();

	return 0;
}