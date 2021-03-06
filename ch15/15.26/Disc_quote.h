#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include <string>
#include "Quote.h"

class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &bn, double p, std::size_t qty, double disc) :
		Quote(bn, p), quantity(qty), discount(disc) { }
	Disc_quote(const Disc_quote&);
	Disc_quote &operator= (const Disc_quote&);
	Disc_quote(Disc_quote&&) noexcept;
	Disc_quote &operator= (Disc_quote&&) noexcept;
	virtual ~Disc_quote() override;
	virtual double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};


#endif