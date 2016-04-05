#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>

int main()
{
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> families;
	std::string lastname, firstname, birthday;
	std::cout << "Please entery lasename, firstname, birthday" << std::endl;
	while (std::cin >> lastname >> firstname >> birthday)
	{
		families[lastname].push_back(std::make_pair(firstname, birthday));
	}
	for (const auto &family : families)
	{
		std::cout << "the following child is the " << family.first
			<< "'s family" << std::endl;
		for (const auto &child : family.second)
			std::cout << child.first << " " << child.second << std::endl;
	}
	return 0;
}