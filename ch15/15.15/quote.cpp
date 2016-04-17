#include <string>
#include "Quote.h"

std::string Quote::isbn() const
{
	return bookNo;
}

double Quote::net_price(std::size_t n) const
{
	return n * price;
}