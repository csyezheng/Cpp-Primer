#include <string>
#include <vector>
#include <map>
#include <iostream>

int main()
{
	std::map<std::string, std::vector<int >> svmap = { {"aa", {1, 1, 1, 1, 1}},
	{"bb", {2, 2, 2, 2, 2}}, {"cc", {3, 3, 3, 3, 3, 3}} };

	std::map<std::string, std::vector<int>>::const_iterator it;

	it = svmap.find("cc");

	for (const auto &elem : it->second)
		std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}