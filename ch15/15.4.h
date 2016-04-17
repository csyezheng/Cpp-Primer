#ifndef QUOTE_H
#define QUOTE_H

#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double p) : bookNo(book), price(p) { }
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
		return price * n;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
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
			return price * n * (1 - discount);
		else
			return price * n;
	}
private:
	std::size_t quantity = 0;
	double discount = 0.0;
};

double print_total(std::ostream&, const Quote&, size_t n);

#endif