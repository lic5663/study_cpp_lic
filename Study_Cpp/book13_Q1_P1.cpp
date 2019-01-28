#include <iostream>
using namespace std;


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

};

template <class T>
void SwapData(T& data1, T& data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;

}

template <class T>
T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main(void)
{

	Point pos1(1, 7);
	Point pos2(10, 70);
	SwapData<Point>(pos1,pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();


	int int_arr[7] = { 1,2,3,4,5,6,7 };
	double double_arr[7] = { 1.4,2.7,3.8,9.4,8.4,2.5,3.7 };
	cout << SumArray<int>(int_arr, 7) << endl;
	cout << SumArray<double>(double_arr, 7) << endl;
	//cout << SumArray<int>(double_arr, 7) << endl;

	return 0;
}