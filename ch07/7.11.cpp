#include <iostream>
#include "Sales_data.h"

int mian()
{
	Sales_data item1;
	Sales_data item2("sfak");
	Sales_data item3("sfak", 8, 9.0);
	Sales_data item4(std::cin);
	return 0;
}