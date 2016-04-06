#include <iostream>
#include <map>
#include <string>

int main()
{
	std::multimap<std::string, std::string> authors;
	std::string author, book;
	std::cout << "Please enter author's name and his book name" << std::endl;
	while (std::cin >> author >> book)
		authors.insert(std::make_pair(author, book));
	auto iter = authors.find("ye");
	if (iter != authors.end())
		authors.erase(iter);
	for (const auto &entry : authors)
		std::cout << entry.first << " " << entry.second << std::endl;
	return 0;
}