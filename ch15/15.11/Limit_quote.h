#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include <string>
#include "Quote.h"
class Limit_quote : public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(const std::string &bn, double p, std::size_t qty, double disc)
		: Quote(bn, p), max_qty(qty), discount(disc) { }
	double net_price(std::size_t n) const override;
	void debug() const override;
private:
	std::size_t max_qty = 0;
	double discount = 0.0;
};


#endif