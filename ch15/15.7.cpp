#include <iostream>
#include "15.7.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	auto ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " sold " << n
		<< " total due: " << ret << std::endl;
	return ret;
}


int main()
{
	Quote item1("dsjaf", 29);
	Little_quote item2("gdlsf", 29, 8, 0.2);
	print_total(std::cout, item1, 6);
	print_total(std::cout, item2, 6);
	return 0;
}