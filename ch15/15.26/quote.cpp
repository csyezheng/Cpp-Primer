#include <string>
#include <iostream>
#include "Quote.h"

Quote::Quote(const std::string &bn, double p) : bookNo(bn), price(p) { }

Quote::Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price)
{
	std::cout << "Quote(const Quote&)" << std::endl;
}

Quote::Quote(Quote &&rhs) : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))
{
	std::cout << "Quote(Quote&&)" << std::endl;
}

Quote &Quote::operator= (const Quote &rhs)
{
	bookNo = rhs.bookNo;
	price = rhs.price;
	std::cout << "Quote &operator(const Quote&)" << std::endl;
	return *this;
}

Quote &Quote::operator= (Quote &&rhs)
{
	bookNo = std::move(rhs.bookNo);
	price = std::move(rhs.price);
	std::cout << "Quote &operator(Quote&&)" << std::endl;
	return *this;
}

std::string Quote::isbn() const
{
	return bookNo;
}

double Quote::net_price(std::size_t n) const
{
	return n * price;
}