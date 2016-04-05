#include <vector>
#include <string>
#include <iostream>
#include <map>

int main()
{
	std::map<std::string, std::vector<std::string>> families;
	std::string last_name, first_name;
	std::cout << "please input fistname and lastname" << std::endl;
	while (std::cin >> first_name >> last_name)
	{
		families[last_name].push_back(first_name);
	}
	for (const auto &elem : families)
	{
		std::cout << elem.first << "'s family have the following child " << std::endl;
		for (const auto &child : elem.second)
			std::cout << child << " ";
		std::cout << std::endl;
	}
	return 0;
}