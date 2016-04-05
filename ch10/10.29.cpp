#include <string>
#include <vector>
#include <iterator>
#include <iostream>

int main()
{
	std::istream_iterator<std::string> iis(std::cin), eof;
	std::vector<std::string> svec(iis, eof);
	for (const auto &elem : svec)
		std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}