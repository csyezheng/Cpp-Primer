#include <iostream>
#include <string>
#include <map>
#include <cstddef>

int main()
{
	std::map<std::string, size_t> word_count;
	std::string word;
	while (std::cin >> word)
		++word_count[word];
	for (const auto &elem : word_count)
	{
		std::cout << elem.first << " occurs " << elem.second
			<< ((elem.second > 1) ? " time " : " times ") << std::endl;
	}
	
	return 0;
}