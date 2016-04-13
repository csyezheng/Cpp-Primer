#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>


class Sales_data
{
	friend std::istream &operator>> (std::istream&, Sales_data&);
	friend std::ostream &operator<< (std::ostream&, const Sales_data&);
public:
	Sales_data(const std::string &s = std::string()) : bookNo(s) { }
	Sales_data(const std::string &s, size_t n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) { }
	Sales_data(std::istream &is) { is >> *this; }
	std::string isbn() const;
	Sales_data &operator+= (const Sales_data&);
private:
	std::string bookNo;
	size_t units_sold = 0;
	double revenue = 0.0;
	double avg_price() const { return revenue / units_sold; }
};

std::istream &operator>> (std::istream &is, Sales_data &item);
std::ostream &operator<< (std::ostream &os, const Sales_data &item);
Sales_data &operator+ (const Sales_data&, const Sales_data&);


#endif