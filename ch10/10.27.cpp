#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

int main()
{
	std::vector<std::string> svec;
	for (std::string str; std::cin >> str; svec.push_back(str));
	std::sort(svec.begin(), svec.end());
	std::list<std::string> slst;
	std::unique_copy(svec.begin(), svec.end(), std::back_inserter(slst));
	std::for_each(slst.cbegin(), slst.cend(),
		[](const std::string &str) { std::cout << str << " "; });
	std::cout << std::endl;
	return 0;
}