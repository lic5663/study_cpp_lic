#include <iostream>
using namespace std;

class SoSimple
{
private :
	int num;
public :
	SoSimple(int n) : num(n) {}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;	//this �����ʹ� ��ü �ڽ��� �ּҰ��� �ǹ��Ѵ�.
	}
	void ShowData() const
	{
		cout << "num : " << num << endl;
	}
};

int main(void)
{
	const SoSimple obj(7);
	SoSimple obj2(8);
	// obj.AddNum(7);	//const�Լ��� �ƴ϶� ����� �Ұ�.
	obj2.AddNum(99);
	obj.ShowData();
	obj2.ShowData();

	return 0;
}