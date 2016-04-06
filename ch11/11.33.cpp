#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>

using std::string;
using std::map;
using std::ifstream;
using std::ofstream;

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
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

const string &transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (std::getline(input, text))
	{
		std::istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
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