#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include "14.39.h"

int main()
{
	std::string range1("1 to 9");
	std::string range2("upper than 9");
	std::map<std::string, std::size_t> statistics = { {range1, 0},
	{range2, 0} };

	Statistic stat(1, 9);

	std::ifstream ifs("sometext.txt");
	if (!ifs)
		throw std::runtime_error("can't open the file");
	std::string line;
	while (ifs >> line)
	{
		std::string word;
		std::istringstream iss(line);
		while (iss >> word)
		{
			if (stat(word))
				++statistics[range1];
			else
				++statistics[range2];
		}
	}

	std::cout << range1 << " " << statistics[range1] << std::endl;
	std::cout << range2 << " " << statistics[range2] << std::endl;
}