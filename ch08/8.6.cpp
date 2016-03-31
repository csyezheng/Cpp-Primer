#include <iostream>
#include <fstream>
#include <string>
#include "../ch07/Sales_data.h"

using namespace std;

int main(int argc, char argv[])
{
	ifstream is;
	is.open(to_string(argv[1]), ifstream::in);
	if (is)
	{
		Sales_data total;
		if (read(is, total))
		{
			Sales_data trans;
			while (read(is, trans))
			{
				if (trans.isbn() == total.isbn())
					total.combine(trans);
				else
				{
					print(cout, total);
					total = trans;
				}
			}
			print(cout, total);
		}
		else
		{
			cerr << "No data?" << endl;
		}
	}
	else
	{
		cerr << "can't open the file" << endl;
	}

	return 0;
}