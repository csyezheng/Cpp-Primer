#include <string>
#include "Bulk_quote.h"

Bulk_quote::Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) { }

Bulk_quote::Bulk_quote(Bulk_quote &&rhs) noexcept : Disc_quote(std::move(rhs)) { }

Bulk_quote &Bulk_quote::operator= (const Bulk_quote &rhs)
{
	Disc_quote::operator= (rhs);
	return *this;
}

Bulk_quote &Bulk_quote::operator= (Bulk_quote &&rhs) noexcept
{
	if (this != &rhs)
		Disc_quote::operator= (std::move(rhs));
	return *this;
}

double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= quantity)
		return n * price * (1 - discount);
	else
		return n * price;
}
