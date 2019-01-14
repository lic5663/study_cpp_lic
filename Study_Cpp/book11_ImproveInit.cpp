#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{
		cout << "AAA(int n = 0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	// �̴ϼȶ������� �ʱ�ȭ -> ����� ���ÿ� �ʱ�ȭ
	BBB(const AAA& ref) : mem(ref) {}
};

class CCC
{
private:
	AAA mem;
public:
	// �̴ϼȶ������� ������� �ʰ� ��ü�κп� ���Կ����� ���� �ʱ�ȭ -> ����� �ʱ�ȭ�� ���� ������ ���忡�� ����
	CCC(const AAA& ref) { mem = ref; }
};

int main(void)
{
	AAA obj1(12);
	cout << "***********************" << endl;
	BBB obj2(obj1); // �����ڸ� ����
	cout << "***********************" << endl;
	CCC obj3(obj1);	// ������, ���Կ����� �Ѵ� �����

	// �̴ϼȶ������� ����Ͽ� �Լ� ȣ��Ƚ���� ���̰� �ʱ�ȭ ���� �ܼ�ȭ ����.
	return 0;
}