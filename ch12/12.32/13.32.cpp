#include <fstream>
#include <stdexcept>
#include "TextQuery.h"

void runQueries(std::ifstream &input)
{
	TextQuery tq(input);
	while (true)
	{
		std::cout << "Enter a word what you want to look for, or q to quit" << std::endl;
		std::string sought;
		if (std::cin >> sought && sought != "q")
		{
			auto ret = tq.query(sought);
			print(std::cout, ret) << std::endl;
		}
		else
			break;
	}
}

int main()
{
	std::ifstream input("text.txt");
	if (!input)
		throw std::runtime_error("can't open the file");
	runQueries(input);
	return 0;
}