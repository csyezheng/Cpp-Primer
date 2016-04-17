#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include <iostream>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &bn, double p) : bookNo(bn), price(p) { }
	Quote(const Quote&) = default;
	Quote &operator= (const Quote&) = default;
	Quote(Quote&&) = default;
	Quote &operator= (Quote&&) = default;
	virtual ~Quote() = default;
	std::string isbn() const
	{
		return bookNo;
	}
	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}
private:
	std::string bookNo;
protected:
	double price;
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &bn, double p, std::size_t qty, double disc)
		: Quote(bn, p), quantity(qty), discount(disc) { }
	double net_price(std::size_t n) const override
	{
		if (n >= quantity)
			return n * price * (1 - discount);
		else
			return n * price;
	}
private:
	std::size_t quantity;
	double discount;
};

double print_total(std::ostream&, const Quote&, std::size_t);

#endif