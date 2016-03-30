// the file name should be Sales_data.h

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
public:
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	// construct functions
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p) { }
	Sales_data(std::istream &is) { read(is, *this); }

	// member functions
	std::string isbn() const
	{
		return bookNo;
	}
	
	Sales_data &combine(const Sales_data &rhs)
	{
		revenue += revenue;
	units_sold += rhs.units_sold;
	return *this;
	}
	
	double avg_price() const
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

private:
	//  member various
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

#endif