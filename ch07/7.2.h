// the file name should be Sales_data.h

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data
{
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
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


#endif