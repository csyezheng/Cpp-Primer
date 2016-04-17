#include <iostream>
#include "Bulk_quote.h"


double Bulk_quote::net_price(std::size_t n) const 
{
	if (n >= quantity)
		return n * price * (1 - discount);
	else
		return n * price;
}


void Bulk_quote::debug() const 
{
	std::cout << "bookNo: " << isbn() << std::endl;
	std::cout << "price: " << price << std::endl;
	std::cout << "quantity: " << quantity << std::endl;
	std::cout << "discount: " << discount << std::endl;
}