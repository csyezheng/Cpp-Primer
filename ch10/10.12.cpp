#include <iostream>
#include <vector>
#include <algorithm>
#include "../ch07/Sales_data.h"

using std::cout; using std::endl;
using std::vector;
using std::stable_sort;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}

int main()
{
	vector<Sales_data> vec = { Sales_data("0219243"), 
		Sales_data("23029234"), Sales_data("13439342") };
	stable_sort(vec.begin(), vec.end(), compareIsbn);
	for (const auto &elem : vec)
		cout << elem.isbn() << " ";
	return 0;
}