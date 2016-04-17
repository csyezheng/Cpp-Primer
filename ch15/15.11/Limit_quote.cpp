#include <iostream>
#include "Limit_quote.h"

double Limit_quote::net_price(std::size_t n) const 
{
	if (n > max_qty)
		return n * price;
	else
		return n * price * (1 - discount);
}

void Limit_quote::debug() const 
{
	Quote::debug();
	std::cout << "max_qty: " << max_qty << std::endl;
	std::cout << "discount: " << discount << std::endl;
}