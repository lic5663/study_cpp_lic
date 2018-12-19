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
		//SoBase(); ������ ���� ���� �����ڰ� ��õǾ� �־ �ν��� ���ϰ� �켱 ���� �����ڸ� �����ϰ� �ѹ��� �Ѵ�.
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
	dr1.ShowDerivData();	// ����, ���� void ������ ȣ��
	cout << "---------------------" << endl;

	cout << "case 2 ....." << endl;
	SoDerived dr2(12);		// ���� �����ڴ� int n���� ���, ���ʴ� ������� �ʾ����Ƿ� void ������ ȣ��
	dr2.ShowDerivData();
	cout << "---------------------" << endl;

	cout << "case 3 ....." << endl;
	SoDerived dr3(23, 24);	// ����, ���� �Ѵ� �����ڸ� ���
	dr3.ShowDerivData();
	cout << "---------------------" << endl;

	// ��� : ���� Ŭ���� ��ü���� �������� ���� Ŭ������ �����ڴ� �ݵ�� ȣ��ȴ�.
	// ���� Ŭ������ ���A�ƿ��� ���� Ŭ������ ������ ȣ���� ������� ���� ��, ���� Ŭ������ void �����ڰ� ȣ���.
	// ������ ȣ�� ������ ������ �켱�̰� ���ʰ� �����̴�.
	// �׷��� ���� �����ڰ� �켱 ȣ��ǰ� ���� �ڵ� ���� ��, ���� �����ڸ� ȣ���Ѵ�. ���� ������ ���� �Ϸ� �� ���� �����ڰ� �۾��� �����Ѵ�.
	return 0;
}