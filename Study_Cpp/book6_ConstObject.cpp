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
		return *this;	//this 포인터는 객체 자신의 주소값을 의미한다.
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
	// obj.AddNum(7);	//const함수가 아니라 사용이 불가.
	obj2.AddNum(99);
	obj.ShowData();
	obj2.ShowData();

	return 0;
}