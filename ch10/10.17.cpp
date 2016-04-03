#include <iostream>
#include <vector>
#include <algorithm>
#include "../ch07/Sales_data.h"

using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main()
{
	vector<Sales_data> vec = { Sales_data("3241091"), Sales_data("24912232"),
	Sales_data("130233"), Sales_data("21909430") };
	sort(vec.begin(), vec.end(), [](const Sales_data &sd1,
		const Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); });
	for (const auto &elem : vec)
		cout << elem.isbn() << endl;
	return 0;
}