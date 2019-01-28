#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	bool operator <(Student &student)
	{
		return this->score < student.score;
	}
};

int main(void)
{
	Student students[] = 
	{
		Student("Seonghwan",90),
		Student("Hwanjun",100),
		Student("Inchan", 80),
		Student("Jogwang",98)
	};

	sort(students, students + 4);
	for (int i = 0; i< 4; i++)
	{
		cout << students[i].name << '\n';
	}
}