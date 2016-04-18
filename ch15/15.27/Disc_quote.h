#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include <string>
#include "Quote.h"

class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string&, double, std::size_t, double);
	Disc_quote(const Disc_quote&);
	Disc_quote(Disc_quote&&) noexcept;
	Disc_quote &operator= (const Disc_quote&);
	Disc_quote &operator= (Disc_quote&&) noexcept;
	~Disc_quote() override { }
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity;
	double discount;
};



#endif