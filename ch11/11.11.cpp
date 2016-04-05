#include <set>
#include "../ch07/Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	using sales_compare = bool(*)(const Sales_data&, const Sales_data&);

	std::multiset<Sales_data, sales_compare>
		bookstore(compareIsbn);
}