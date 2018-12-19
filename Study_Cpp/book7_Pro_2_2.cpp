#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(char* booktitle, char* bookisbn, int bookprice) : price(bookprice)
	{
		title = new char[strlen(booktitle) + 1];
		strcpy(title, booktitle);

		isbn = new char[strlen(bookisbn) + 1];
		strcpy(isbn, bookisbn);
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
	void ShowBookInfo() const
	{
		cout << "제목 : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "가격 : " << price << endl;
	}
};

class EBook : public Book
{
private:
	char * DRMKey;
public:
	EBook(char* booktitle, char* bookisbn, int bookprice, char* DRM) : Book(booktitle, bookisbn, bookprice)
	{
		DRMKey = new char[strlen(DRM) + 1];
		strcpy(DRMKey, DRM);
	}
	~EBook()
	{
		delete[] DRMKey
	}
	void ShowEBookInfo() const
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int main(void)
{
	Book book("좋은 c++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은c ++ ebook", "557-18941-894-7", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();


	return 0;
}