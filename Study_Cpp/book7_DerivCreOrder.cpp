#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public :
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData() const
	{
		cout << "base Num : "  << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private :
	int derivNum;
public :
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived() " << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n) " << endl;
		//SoBase(); 생성자 내에 기초 생성자가 명시되어 있어도 인식을 못하고 우선 기초 생성자를 실행하고 한번더 한다.
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData() const
	{
		ShowBaseData();
		cout << "derivNum : " << derivNum << endl;
	}
};

int main(void)
{
	cout << "case 1 ....." << endl;
	SoDerived dr1;	
	dr1.ShowDerivData();	// 기초, 유도 void 생성자 호출
	cout << "---------------------" << endl;

	cout << "case 2 ....." << endl;
	SoDerived dr2(12);		// 유도 생성자는 int n으로 명시, 기초는 명시하지 않았으므로 void 생성자 호출
	dr2.ShowDerivData();
	cout << "---------------------" << endl;

	cout << "case 3 ....." << endl;
	SoDerived dr3(23, 24);	// 유도, 기초 둘다 생성자를 명시
	dr3.ShowDerivData();
	cout << "---------------------" << endl;

	// 결론 : 유도 클래스 객체생성 과정에서 기초 클래스의 생성자는 반드시 호출된다.
	// 유도 클래스의 생섲아에서 기초 클래스의 생성자 호출을 명시하지 않을 시, 기초 클래스의 void 생성자가 호출됨.
	// 생성자 호출 순서는 유도가 우선이고 기초가 나중이다.
	// 그러나 유도 생성자가 우선 호출되고 내부 코드 실행 전, 기초 생성자를 호출한다. 기초 생성자 진행 완료 후 유도 생성자가 작업을 수행한다.
	return 0;
}