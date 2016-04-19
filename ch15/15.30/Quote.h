#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <memory>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &bn, double p);
	Quote(const Quote&);
	Quote &operator= (const Quote&);
	Quote(Quote &&) noexcept;
	Quote &operator= (Quote&&) noexcept;
	virtual ~Quote() = default;
	std::string isbn() const;
	virtual double net_price(std::size_t) const;
	virtual Quote *clone() const &;
	virtual Quote *clone() && ;
private:
	std::string bookNo;
protected:
	double price;
};


#endif