#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include "Quote.h"

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &bn, double p, std::size_t qty, double disc) :
		Quote(bn, p), quantity(qty), discount(disc) { }
	double net_price(std::size_t n) const override;
	void debug() const override;
private:
	std::size_t quantity = 0;
	double discount = 0.0;
};



#endif