#include <iostream>
#include "7.2.h"

using namespace std;

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (trans.isbn() == total.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout << total.isbn() << " " << total.units_sold << " "
					<< total.revenue << " " << total.avg_price() << endl;
			}
		}
		cout << trans.isbn() << " " << trans.units_sold << " "
			<< trans.revenue << " " << trans.avg_price() << endl;
	}
	else
	{
		cerr << "No data?" << endl;
	}
	return 0;
}