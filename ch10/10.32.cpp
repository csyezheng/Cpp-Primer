#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "../ch07/Sales_data.h"

using std::string;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}

int main()
{
	Sales_data trans;
	std::vector<Sales_data> vec;
	while (read(std::cin, trans))
		vec.push_back(trans);
	for (auto beg = vec.begin(), end_same = beg; beg != vec.end(); beg = end_same)
	{
		//end_same = std::find_if(beg, vec.end(),
			//[beg](const Sales_data &sd) { return sd.isbn() != beg->isbn(); });
		
		//print(std::cout, std::accumulate(beg, end_same, Sales_data(beg->isbn())));
	}
	return 0;
}