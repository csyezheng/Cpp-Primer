#include <iostream>
#include <stdexcept>
#include <fstream>
#include "14.38.h"


int main()
{
	std::vector<Statistic> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::ifstream input("sometext.txt");
	//if (!input)
		//throw std::runtime_error("can't open the file");
	std::string line;
	while (ifs >> line)
	{
		std::string word;
		std::istringstream iss(line);
		while (iss >> word)
		{
			for (const auto &entry : vec)
				if (entry(word))
					entry.incr_count();
		}
	}
	size_t i = 1;
	for (const auto &elem : vec)
		std::cout << i++ << ": " << elem.print() << std::endl;
	return 0;
}