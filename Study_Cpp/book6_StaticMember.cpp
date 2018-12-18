#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;
public :
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex
{
private :
	static int cmpObjCnt;
public :
	SoComplex()
	{
		cmpObjCnt++;
		cout << cmpObjCnt << "��° soComplex ��ü" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmpObjCnt++;
		cout << cmpObjCnt << "��° soComplex ��ü" << endl;
	}
};

int SoSimple::simObjCnt = 0;
int SoComplex::cmpObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}