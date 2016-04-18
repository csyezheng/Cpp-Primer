#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include "Disc_quote.h"

class Bulk_quote : Disc_quote
{
public:
	Bulk_quote() = default;
	using Disc_quote::Disc_quote;
	Bulk_quote(const Bulk_quote&);
	Bulk_quote &operator= (const Bulk_quote&);
	Bulk_quote(Bulk_quote&&) noexcept;
	Bulk_quote &operator= (Bulk_quote&&) noexcept;
	~Bulk_quote() override { }
	double net_price(std::size_t n) const override;
};




#endif