#include <stdexcept>
#include <iostream>
#include <string>
#include "Sales_data.h"

using std::string;
using std::ostream;
using std::istream;
using std::runtime_error;

string Sales_data::isbn() const
{
	return bookNo;
}

Sales_data::operator string() const
{
	return bookNo;
}

Sales_data::operator double() const 
{
	return avg_price();
}

istream &operator>> (istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

ostream &operator<< (ostream &os, const Sales_data &item)
{
	os << item.bookNo << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

bool operator== (const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold
		&& lhs.revenue == lhs.revenue;
}

Sales_data &Sales_data::operator+= (const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
		throw runtime_error("the two Sales_data have difference bookNo");

	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data &Sales_data::operator= (const std::string &bn)
{
	*this = Sales_data(bn);         ////////////////////////////////////////////////////////
	return *this;
}

Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data total = lhs;
	total += rhs;
	return total;
}

Sales_data operator- (const Sales_data &lhs, const Sales_data &rhs)
{
	if (lhs.isbn() != rhs.isbn())
		throw runtime_error("the two Sales_data have difference booNo");
	Sales_data ret = lhs;
	ret.units_sold -= rhs.units_sold;
	ret.revenue -= rhs.revenue;
	return ret;
	
}

double Sales_data::avg_price() const
{
	return revenue / units_sold;
}

