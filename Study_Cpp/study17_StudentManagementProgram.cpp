#include <iostream>
using namespace std;

#define NAME_SIZE		32
#define STUDENT_MAX		10
#define ADDRESS_SIZE	128
#define PHONE_SIZE		14

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	// 배열에 저장된 수 카운터용 변수
	int iStudentCount = 0;
	int iStdNumber = 1;
	char strName[NAME_SIZE] = {};

	while (true)
	{
		system("cls");

		// 메뉴 출력
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		
		int iMenu;
		cin >> iMenu;
		// cin에 문자가 입력될시 강제 무한 루프 발생
		// 에러 발생시 내부 버퍼를 비워주도록 해서
		// 무한루프 발생을 막는다.

		// 에러 체크
		// cin에서 입력 에러 발생시 true를 반환한다.
		if (cin.fail())
		{
			// 에러버퍼 비워줌
			cin.clear();
			// 입력 버퍼에 \n이 남아있으므로 입력버퍼를
			// 검색하여 \n을 지운다

			// 좌측: 검색할 버퍼 크기, 우측: 찾고자 하는 문자
			// 입력버퍼 처음부터 \n이 있는곳 까지 찾아 해당
			// 부분을 모두 제거해서 정상 입력이 가능하도록
			// 만든다
			cin.ignore(1024, '\n');
		}
		

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			// 등록된 학생이 최대일 경우 등록을 막음
			if (iStudentCount == STUDENT_MAX)
			{
				cout << "등록 최대 수 도달" << endl;
				break;
			}

			// 학생정보 추가. 
			// 학번, 주소, 전화, 이름, 국어, 영어, 수학, 총점, 평균
			system("cls");
			cout << "=================== 학생 추가 ===================" << endl;

			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;
			// 후발 cin 영향 제거용
			cin.ignore(1024, '\n');
			

			cout << "주소 : ";
			// cin은 공백도 끝으로 인식함으로 부적절
			// cin >> tStudentArr[iStudentCount].strAddress;
			// cin.getline(받을 변수, 버퍼값)
			// 그러나 cin.getline 전 cin을 사용시 버퍼에 엔터가
			// 남아 정상적으로 작동되지 않는다.
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "휴대폰 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber,PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;
			tStudentArr[iStudentCount].iNumber = iStdNumber;
			
			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			// 사전에 저장된 값이 없으면 종료
			if (iStudentCount == 0)
			{
				cout << "저장된 학생이 없습니다." << endl << endl;
				break;
			}
			cout << "=================== 학생 삭제 ===================" << endl;
			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 :";
			cin.getline(strName, NAME_SIZE);
		
			for (int i = 0; i < iStudentCount; i++)
			{
				// 삭제할 대상이 존재하는 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; j++)
					{
						tStudentArr[i] = tStudentArr[i + 1];
					}
					--iStudentCount;
					cout << "학생을 성공적으로 제거했습니다." << endl;
				}
				else if (i == (iStudentCount-1))
				{
					cout << "해당 학생은 존재하지 않습니다" << endl << endl;
					break;
				}
			}

			break;
		case MENU_SEARCH:
			// 이름으로 검색한다.
			system("cls");
			cout << "=================== 학생 탐색 ===================" << endl;
			// 사전에 저장된 데이터가 존재하지 않으면 종료
			if (iStudentCount == 0)
			{
				cout << "저장된 학생이 없습니다." << endl<<endl;
				break;	
			}
			// switch문 내부에 변수 선언시 초기화 문제가 발생한다.
			//char strSeachName[NAME_SIZE] = {};
			// 따라서 해당 부분을 while문 밖에 선언
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 :";
			cin.getline(strName,NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				//찾을 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이름 :" << tStudentArr[i].strName << endl;
					cout << "주소 :" << tStudentArr[i].strAddress << endl;
					cout << "전화번호 :" << tStudentArr[i].strPhoneNumber << endl;
					cout << "학번 :" << tStudentArr[i].iNumber << endl;
					cout << "국어 :" << tStudentArr[i].iKor << endl;
					cout << "영어 :" << tStudentArr[i].iEng << endl;
					cout << "수학 :" << tStudentArr[i].iMath << endl;
					cout << "총합 :" << tStudentArr[i].iTotal << endl;
					cout << "평균 :" << tStudentArr[i].fAvg << endl << endl;
					break;
				}
				else if (i == (iStudentCount - 1))
					cout << "해당 학생은 존재하지 않습니다." << endl << endl;
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "=================== 학생 출력 ===================" << endl;
			// 사전에 저장된 값이 없으면 종료
			if (iStudentCount == 0)
			{
				cout << "저장된 학생이 없습니다." << endl<< endl;
				break;
			}
			
			// 등록된 학생 수만큼 반복하며 출력
			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "이름 :" << tStudentArr[i].strName << endl;
				cout << "주소 :" << tStudentArr[i].strAddress << endl;
				cout << "전화번호 :" << tStudentArr[i].strPhoneNumber << endl;
				cout << "학번 :" << tStudentArr[i].iNumber << endl;
				cout << "국어 :" << tStudentArr[i].iKor << endl;
				cout << "영어 :" << tStudentArr[i].iEng << endl;
				cout << "수학 :" << tStudentArr[i].iMath << endl;
				cout << "총합 :" << tStudentArr[i].iTotal << endl;
				cout << "평균 :" << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "잘못된 메뉴 선택!" << endl;
			break;
		}
		system("pause");

	}

	return 0;
}