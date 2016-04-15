#include <vector>
#include <string>
#include <iostream>
#include "14.35.h"

int main()
{
	std::vector<std::string> vec;
	std::string str;
	for (size_t i = 0; i != 10; ++i)
	{
		vec.push_back(Print_String()(str));
	}
	for (const auto &s : vec)
		std::cout << s << std::endl;
}