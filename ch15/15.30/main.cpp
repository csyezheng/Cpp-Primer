#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Basket.h"

int main()
{
	
	Basket car;
	car.add_items(Quote("0001", 25));
	car.add_items(Bulk_quote("0002", 12, 8, 0.3));
	car.add_items(Quote("0003", 19));
	car.add_items(Bulk_quote("0004", 32, 12, 0.5));
	auto total = car.total_receipt(std::cout);

	return 0;
}