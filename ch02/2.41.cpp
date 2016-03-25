#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data data;
	double price = 0.0;
	if (std::cin >> data.bookNo >> data.units_sold >> price)
	{
		data.revenue = data.units_sold * price;
		Sales_data data1;
		while (std::cin >> data1.bookNo >> data.units_sold >> price)
		{
			data1.revenue = data.units_sold * price;
			if (data.bookNo == data1.bookNo)
			{
				data.units_sold += data1.units_sold;
				data.revenue += data1.revenue;
			}
			else
			{
				std::cout << data.bookNo << " " << data.units_sold 
					<< " "<< data.revenue << std::endl;
				data.bookNo = data1.bookNo;
				data.units_sold = data.units_sold;
				data.revenue = data.revenue;
			}
		}
		std::cout << data.bookNo << " " << data.units_sold
			<< " " << data.revenue << std::endl;
	}
	else
	{
		std::cerr << "No data" << std::endl;
		return 0;
	}

	return 0;
}