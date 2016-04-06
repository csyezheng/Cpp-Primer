#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <cstddef>

int main()
{
	std::map<std::string, std::size_t> word_cnt;
	std::string word;
	while (std::cin >> word)
	{
		auto ret = word_cnt.insert(std::make_pair(word, 1));
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto &entry : word_cnt)
	{
		std::cout << entry.first << " occur " << entry.second
			<< ((entry.second > 1) ? " times " : " time ") << std::endl;
	}
	return 0;
}