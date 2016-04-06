#include <iostream>
#include <map>
#include <string>

int main()
{
	std::multimap<std::string, std::string> authors =
	{
		{"Chris", "computer science"},
		{"Smith", "Algorithms"},
		{"Marisa", "Database"},
		{"Smith", "computer orgnization"},
		{"Chris", "Compiler"},
		{"Marisa", "Operation System"}
	};
	for (const auto &entry : authors)
	{
		std::cout << entry.first << " " << entry.second << std::endl;
	}
	return 0;
}