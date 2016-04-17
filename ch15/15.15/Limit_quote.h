#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "Disc_quote.h"

class Limit_quote : public Disc_quote
{
public:
	Limit_quote() = default;
	double net_price(std::size_t n) const override
	{
		if (n > quantity)
			return n * price;
		else
			return n * price * (1 - discount);
	}
};



#endif