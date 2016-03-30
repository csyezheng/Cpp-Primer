#include <iostream>
#include "7.41.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	cout << "-------------default--------------------" << endl;
	Sales_data();
	cout << "--------------bookNo---------------------" << endl;
	Sales_data("bn1303240249");
	cout << "------bookNo----units_sold-----revenue---" << endl;
	Sales_data("bn2930292393", 25, 2.2);
	cout << "-------------istream-------------" << endl;
	Sales_data(cin);
	
	return 0;
}