#include <iostream>
#include "15.6.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " sold " << n
		<< " total due: " << ret << std::endl;
	return ret;
}


int main()
{
	Quote base("00001", 5);
	Bulk_quote derived("00002", 5, 15, 0.4);
	print_total(std::cout, base, 35);
	print_total(std::cout, derived, 35);

	return 0;
}