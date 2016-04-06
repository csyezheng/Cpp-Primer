#include <set>
#include "../ch07/Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	using compareSales_data = bool(*)(const Sales_data&, const Sales_data&);
	using multisetSales_data = std::multiset<Sales_data, compareSales_data>;
	multisetSales_data bookstore(compareIsbn);
	multisetSales_data::iterator iter = bookstore.begin();
	
	return 0;
}