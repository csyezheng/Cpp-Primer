#ifndef QUOTE_H
#define QUOTE_H

#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &bn, double p) : bookNo(bn), price(p) { }
	Quote(const Quote&) = default;
	Quote(Quote&&) = default;
	Quote &operator= (const Quote&) = default;
	Quote &operator= (Quote&&) = default;
	virtual ~Quote() = default;
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


#endif