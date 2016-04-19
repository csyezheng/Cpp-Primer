#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	using Disc_quote::Disc_quote;
	Bulk_quote(const Bulk_quote&);
	Bulk_quote &operator= (const Bulk_quote&);
	Bulk_quote(Bulk_quote&&) noexcept;
	Bulk_quote &operator= (Bulk_quote&&) noexcept;
	~Bulk_quote() override = default;
	double net_price(std::size_t) const override;
	Bulk_quote *clone() const & override;
	Bulk_quote *clone() && override;
};



#endif