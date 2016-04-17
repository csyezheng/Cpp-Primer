#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include "Disc_quote.h"

class Bulk_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &bn, double p, std::size_t qty, double disc) :
		Disc_quote(bn, p, qty, disc) { }
	Bulk_quote(const Bulk_quote&);
	Bulk_quote &operator= (const Bulk_quote&);
	Bulk_quote(Bulk_quote&&);
	Bulk_quote &operator= (Bulk_quote&&);
	double net_price(std::size_t) const override;
};


#endif