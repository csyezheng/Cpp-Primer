#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

int main()
{
	std::cout << "-----------create two Bulk_quote objects----------" << std::endl;
	Bulk_quote item1, item2;
	std::cout << "-----------------copy assignment------------" << std::endl;
	item1 = item2;
	std::cout << "-----------------move assignment------------" << std::endl;
	item1 = std::move(item2);
	std::cout << "-----------------then it will be destroy-------" << std::endl;
}