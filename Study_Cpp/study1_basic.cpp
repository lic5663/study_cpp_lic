#include <iostream>
// # : 전처리기
// #include : 헤더파일을 여기에 포함한다.

using namespace std;

// 실행 과정 : 컴파일 -> 빌드 -> 실행
// 컴파일 : 번역작업.
// ctrl + shift + B : 컴파일 및 빌드

// c++의 시작점은 main 함수.
int main(void)
{	
	// 대부분 기능은 std라는 namespace 내부 함수 사용
	// cout : 콘솔창에 " "의 문자, 문자열 출력
	std::cout << "Hello World" << std::endl;
	std::cout << "Test output" << std::endl;
	cout << "std namespace 사용" << endl;
	return 0;
}