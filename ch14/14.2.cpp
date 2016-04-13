#include <iostream>
#include <string>
#include "14.2.h"

std::istream &operator>> (std::istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

std::ostream &operator<< (std::ostream &os, const Sales_data &item)
{
	os << item.bookNo << " " << item.units_sold 
		<< " " << item.revenue << " " << item.avg_price();
	return os;
}

std::string Sales_data::isbn() const
{
	return bookNo;
}

Sales_data &Sales_data::operator+= (const Sales_data &rhs)
{
	if (isbn() == rhs.isbn())
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}
	else
		throw std::runtime_error("the two Sales_data have different bookNo");
}

Sales_data &operator+ (const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data total = lhs;
	total += rhs;
	return total;
}

int main()
{

}