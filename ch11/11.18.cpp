#include <string>
#include <cstddef>
#include <map>
#include <iostream>
#include <algorithm>

int main()
{
	using word_cnt_map = std::map<std::string, std::size_t>;
	word_cnt_map word_cnt;
	std::string word;
	while (std::cin >> word)
		++word_cnt[word];
	word_cnt_map::const_iterator map_it = word_cnt.cbegin();
	std::for_each(map_it, word_cnt.cend(), [](const auto &entry) {
		std::cout << entry.first << " " << entry.second << std::endl; });
	return 0;
}