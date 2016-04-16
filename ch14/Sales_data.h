#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
	friend std::istream& operator>> (std::istream&, Sales_data&);
	friend std::ostream& operator<< (std::ostream&, const Sales_data&);
	friend Sales_data operator+ (const Sales_data&, const Sales_data&);
	friend bool operator== (const Sales_data&, const Sales_data&);
	friend Sales_data operator- (const Sales_data&, const Sales_data&);
public:
	Sales_data(const std::string &bn = std::string()) :
		Sales_data(bn, 0, 0.0) { }
	Sales_data(const std::string &bn, unsigned n, double p) :
		bookNo(bn), units_sold(n), revenue(n * p) { }
	Sales_data(std::istream &is) { is >> *this; }
	Sales_data &operator+= (const Sales_data&);
	Sales_data &operator= (const std::string&);
	std::string isbn() const;
	explicit operator std::string() const;
	explicit operator double() const;
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
	double avg_price() const;
};


std::istream &operator>> (std::istream&, Sales_data&);
std::ostream &operator<< (std::ostream&, const Sales_data&);
bool operator== (const Sales_data&, const Sales_data&);
Sales_data operator+ (const Sales_data&, const Sales_data&);
Sales_data operator- (const Sales_data&, const Sales_data&);


#endif