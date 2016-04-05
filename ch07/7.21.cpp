#include <iostream>
#include "Sales_data.h"

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data total = lhs;
	total.combine(rhs);
	return total;
}

std::istream &operator >> (std::istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &operator << (std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price() << std::endl;
	return os;
}

Sales_data operator+(const Sales_data &sd1, const Sales_data &sd2)
{
	Sales_data temp = sd1;
	temp.combine(sd2);
	return temp;
}