#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
	friend bool operator== (const Sales_data &lhs, const Sales_data &rhs);
	friend std::ostream &operator<< (std::ostream&, const Sales_data&);
	friend std::istream &operator>> (std::istream&, Sales_data&);
public:
	Sales_data() : Sales_data(" ") { }
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(n * p) { }
	Sales_data(std::istream &is) { is >> *this; }
	std::string isbn() const;
	Sales_data &operator += (const Sales_data&);
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
};

std::istream &operator>> (std::istream&, Sales_data&);
std::ostream &operator<< (std::ostream&, const Sales_data&);
Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs);
bool operator== (const Sales_data &lhs, const Sales_data &rhs);

#endif