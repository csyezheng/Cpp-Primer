#include <map>
#include <string>
#include <iostream>

int main()
{
	std::multimap<std::string, std::string> families;
	std::string firstname, lastname;
	std::cout << "Please enter firstname and lastname" << std::endl;
	while (std::cin >> firstname >> lastname)
		families.insert(std::make_pair(lastname, firstname));
	for (const auto &entry : families)
		std::cout << entry.first << " " << entry.second << std::endl;
	return 0;
}