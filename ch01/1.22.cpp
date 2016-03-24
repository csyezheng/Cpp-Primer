#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	Sales_item currBook, book;
	if (cin >> book)
	{
		currBook = book;
		while (cin >> book)
		{
			if (currBook.isbn() == book.isbn())
				currBook += book;
			else
			{
				cout << currBook << endl;
				currBook = book;
			}
		}
		cout << currBook << endl;
	}
	else
	{
		cerr << "No data?" << endl;
	}
	return 0;
}