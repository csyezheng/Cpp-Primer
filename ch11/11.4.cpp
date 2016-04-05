#include <iostream>
#include <string>
#include <cstddef>
#include <map>
#include <algorithm>

int main()
{
	std::map<std::string, std::size_t> word_count;
	std::string word;
	while (std::cin >> word)
	{
		word.erase(std::remove_if(word.begin(), word.end(), ispunct));
		for (auto &ch : word)
			ch = tolower(ch);
		++word_count[word];
	}
	for (const auto &entry : word_count)
	{
		std::cout << entry.first << " occurs " << entry.second
			<< ((entry.second > 1) ? " times " : " time ") << std::endl;
	}
	return 0;
}