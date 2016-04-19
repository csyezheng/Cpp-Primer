#include <iostream>
#include "Basket.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	auto ret = item.net_price(n);
	os << item.isbn() << " sold: " << n << " total due " << ret << std::endl;
	return ret;
}

double Basket::total_receipt(std::ostream &os) const
{
	double total = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		auto trans = print_total(os, **iter, items.count(*iter));
		total += trans;
	}
	return total;
}
