#include <iostream>
#include <string>
#include "15.4.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " sold: " << n
		<< " total due " << ret << std::endl;
	return ret;
}

int main()
{
	Quote base("00001", 2);
	Bulk_quote derived("00002", 2, 10, 0.3);
	print_total(std::cout, base, 20);
	print_total(std::cout, derived, 20);
	return 0;
}