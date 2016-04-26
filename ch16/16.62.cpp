#include <iostream>
#include <unordered_set>
#include "16.62.h"

int main()
{
	std::unordered_multiset<Sales_data> um;
	Sales_data item1("fsdjak"), item2("dasfjk"), item3("fiaj");
	um.insert(item1);
	um.insert(item2);
	um.insert(item3);
	for (const auto &entry : um)
		std::cout << entry.isbn() << std::endl;
	return 0;
}