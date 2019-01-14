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
	// 이니셜라이저로 초기화 -> 선언과 동시에 초기화
	BBB(const AAA& ref) : mem(ref) {}
};

class CCC
{
private:
	AAA mem;
public:
	// 이니셜라이저를 사용하지 않고 몸체부분에 대입연산을 통해 초기화 -> 선언과 초기화를 각각 별도의 문장에서 진행
	CCC(const AAA& ref) { mem = ref; }
};

int main(void)
{
	AAA obj1(12);
	cout << "***********************" << endl;
	BBB obj2(obj1); // 생성자만 실행
	cout << "***********************" << endl;
	CCC obj3(obj1);	// 생성자, 대입연산자 둘다 실행됨

	// 이니셜라이저를 사용하여 함수 호출횟수를 줄이고 초기화 과정 단순화 가능.
	return 0;
}