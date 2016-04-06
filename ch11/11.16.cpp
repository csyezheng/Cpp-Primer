#include <iostream>
#include <map>
#include <cstddef>
#include <string>

int main()
{
	std::map<std::string, std::size_t> word_cnt = { {"the", 2},
	{"and", 4}, {"is", 10} };
	auto beg = word_cnt.begin();
	beg->second = 3;
	for (const auto &entry : word_cnt)
		std::cout << entry.first << " " << entry.second << std::endl;
	return 0;
}