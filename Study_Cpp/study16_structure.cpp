#include <iostream>
using namespace std;
#define NAME_SIZE 64
/*
구조체 : 관련 변수를 모아서 하나의 새로운 타입생성
사용자 정의 변수 타입.
형태 : struct 구조체명 {};

배열과 구조체 공통점
1. 데이터 집합
2. 연속된 메모리 블럭에 할당. 구조체 멤버들은 연속된
메모리 블럭으로 잡힌다.

*/
struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	int		iNumber;
	float	fAvg;
};

int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// 구조체 크기는 내부 변수 크기 합
	cout << "_tagStudent 크기 :" << sizeof(_tagStudent) << endl;
	cout << "tStudent 크기 :" << sizeof(tStudent) << endl;
	cout << "tStudentArr 크기 :" << sizeof(tStudentArr) << endl;

	// 구조체 멤버 접근시 구조체.변수명 형태로 접근
	tStudent.iKor = 100;

	// tStudent.strName = "dknf"; -> 에러 발생
	// 문자열을 배열에 넣을 때에는 단순 대입으로 불가능
	// strcpy_s 함수로 문자열을 복사해야한다.

	// 문자열의 끝은 항상 0(NULL)로 끝나야한다.
	// 쓰레기값이 이미 삽입되어있을 경우 문자열
	// 끝을 알 수 없기에 쓰레기값도 같이 나온다.
	strcpy_s(tStudent.strName, "사람");
	// strcpy_s 는 대입하고 자동으로 끝에 NULL을 삽입 

	// strcat_s 함수 : 좌측에 우측 문자열 붙이기
	strcat_s(tStudent.strName, " 안녕");

	// strcmp 함수 : 두 문자열 비교하여 같을 경우 0,
	// 다를 경우 0이 아닌 값을 반환한다.

	strcpy_s(tStudent.strName, "홍길동");
	cout << "비교할 이름을 입력하시오 :";
	char strName[NAME_SIZE];
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "해당 학생이 존재합니다" << endl;
	}

	cout << "이름 :" << tStudent.strName << endl;
	cout << "학번 :" << tStudent.iNumber << endl;
	cout << "국어 :" << tStudent.iKor << endl;
	cout << "영어 :" << tStudent.iEng << endl;
	cout << "수학 :" << tStudent.iMath << endl;
	cout << "총점 :" << tStudent.iTotal << endl;
	cout << "평균 :" << tStudent.fAvg << endl;
	cout << "이름 크기 :" << sizeof(tStudent.strName) << endl;
	cout << "이름 길이 :" << strlen(tStudent.strName) << endl;

	return 0;
}