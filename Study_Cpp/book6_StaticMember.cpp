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
		cout << simObjCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
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
		cout << cmpObjCnt << "¹øÂ° soComplex °´Ã¼" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmpObjCnt++;
		cout << cmpObjCnt << "¹øÂ° soComplex °´Ã¼" << endl;
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