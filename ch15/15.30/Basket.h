#ifndef BASKET_H
#define BASKET_H

#include <set>
#include <memory>
#include "Quote.h"
#include "Bulk_quote.h"

class Basket
{
public:
	void add_items(const Quote &sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));         // use shared_ptr instead of make shared
	}
	void add_items(Quote &&sale)
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };  /////////{ }
};

double print_total(std::ostream&, const Quote &, std::size_t);

#endif