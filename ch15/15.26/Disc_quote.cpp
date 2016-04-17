#include <string>
#include <iostream>
#include "Disc_quote.h"

Disc_quote::Disc_quote(const Disc_quote &rhs) : Quote(rhs) { }

Disc_quote &Disc_quote::operator= (const Disc_quote &rhs)
{
	Quote::operator= (rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;
	std::cout << "Disc_quote &operator= (const Disc_quote&)" << std::endl;
	return *this;
}

Disc_quote::Disc_quote(Disc_quote &&rhs) :
	Quote(std::move(rhs)),
	quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount))
{
	std::cout << "Disc_quote(Disc_quote&&)" << std::endl;
}

Disc_quote &Disc_quote::operator= (Disc_quote &&rhs)
{
	Quote::Quote(std::move(rhs));
	quantity = st
}