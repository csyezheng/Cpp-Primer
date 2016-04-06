#include <iostream>
#include <string>
#include <unordered_map>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::ifstream;

/* word_count */
void word_cnt()
{
	std::unordered_map<string, std::size_t> word_count;
	string word;
	while (std::cin >> word)
		++word_count[word];
	for (const auto &elem : word_count)
	{
		std::cout << elem.first << " occur " << elem.second
			<< ((elem.second > 1) ? " times " : " time ") << std::endl;
	}
}

/* word_transform */
std::unordered_map<string, string> buildMap(ifstream &map_file)
{
	std::unordered_map<string, string> trans_map;
	string oldStr, newStr;
	while (map_file >> oldStr && std::getline(map_file, newStr))
	{
		if (newStr.size() > 1)
			trans_map[oldStr] = newStr.substr(1);
		else
			throw std::runtime_error("no rule for " + oldStr);
		return trans_map;
	}
}

const string &transform(const string &s, 
	const std::unordered_map<string, string> trans_map)
{
	auto iter = trans_map.find(s);
	if (iter != trans_map.cend())
		return iter->second;
	else
		return s;
}

void word_transform(ifstream &ifs_map, ifstream &input)
{
	auto trans_map = buildMap(ifs_map);
	string text;
	while (std::getline(input, text))
	{
		std::istringstream stream(text);
		string word;
		bool first_word = true;
		while (stream >> word)
		{
			if (first_word)
				first_word = false;
			else
				std::cout << " " << std::endl;
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

int main()
{
	ifstream input("toBeChanged.txt"), ifs_map("transformRule.txt");
	if (input && ifs_map)
		word_transform(ifs_map, input);
	else
		std::cerr << "can't open file" << std::endl;
	return 0;
}