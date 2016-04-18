#include <string>
#include "Disc_quote.h"

Disc_quote::Disc_quote(const std::string &bn, double p, std::size_t n, double disc) :
	Quote(bn, p), quantity(n), discount(disc) { }

Disc_quote::Disc_quote(const Disc_quote &rhs) :
	Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) { }

Disc_quote &Disc_quote::operator= (const Disc_quote &rhs)
{
	Quote::operator=(rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;
	return *this;
}

Disc_quote::Disc_quote(Disc_quote &&rhs) noexcept:
Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) { }

Disc_quote &Disc_quote::operator= (Disc_quote &&rhs) noexcept
{
	Quote::operator= (std::move(rhs));
	quantity = std::move(rhs.quantity);
	discount = std::move(rhs.discount);
	return *this;
}