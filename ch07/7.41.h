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
	Sales_data() : Sales_data(" ", 0, 0)
	{
		std::cout << "Sales_data()" << std::endl;
	}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0)
	{
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p)
	{
		std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;
	}
	Sales_data(std::istream &is): Sales_data()
	{ 
		read(is, *this); 
		std::cout << "Sales_data(std::istream&)" << std::endl;
	}

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




// the following code should be define in other file
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data total = lhs;
	total.combine(rhs);
	return total;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price() << std::endl;
	return os;
}
#endif