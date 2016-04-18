#include <string>
#include "Quote.h"

Quote::Quote(const std::string &bn, double p) : bookNo(bn), price(p) { }

Quote::Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) { }

Quote &Quote::operator= (const Quote &rhs)
{
	bookNo = rhs.bookNo;
	price = rhs.price;
	return *this;
}

Quote::Quote(Quote &&rhs) noexcept: bookNo(std::move(bookNo)), price(std::move(price)) { }

Quote &Quote::operator= (Quote &&rhs) noexcept
{
	if (this != &rhs)
	{
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
	}
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
