#include <string>
#include <iostream>
#include <stdexcept>
#include "14.9.h"

std::string Sales_data::isbn() const
{
	return bookNo;
}

Sales_data &Sales_data::operator+= (const Sales_data &rhs)
{
	if (isbn() == rhs.isbn())
	{
		units_sold += rhs.units_sold;
		revenue = rhs.revenue;
	}
	else
		throw std::runtime_error("the two Sales_data have different bookNo");
	return *this;
}

Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data total = lhs;
	total += rhs;
	return total;
}

double Sales_data::avg_price() const
{
	return revenue / units_sold;
}

bool operator== (const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold
		&& lhs.avg_price() == rhs.avg_price();
}

std::istream& operator>> (std::istream &is, Sales_data &sd)
{
	double price;
	is >> sd.bookNo >> sd.units_sold >> price;
	if (is)
		sd.revenue = sd.units_sold * price;
	else
		sd = Sales_data();
	return is;
}

std::ostream &operator<< (std::ostream &os, const Sales_data &sd)
{
	os << sd.isbn() << " " << sd.units_sold << " "
		<< sd.revenue << " " << sd.avg_price();
	return os;
}

int main()
{

}