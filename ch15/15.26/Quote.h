#ifndef QUOTE_H
#define QUOTE_H

#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string&, double p);
	Quote(const Quote&);
	Quote(Quote&&);
	Quote &operator= (const Quote&);
	Quote &operator= (Quote&&);
	virtual ~Quote() = default;
	std::string isbn() const;
	virtual double net_price(std::size_t) const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};



#endif