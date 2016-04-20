#include <vector>
#include <list>
#include <iostream>
#include <string>
#include "16.4.h"

int main()
{
	std::vector<std::string> svec = { "sdf", "jsaflk", "sdjk", "asdf", "daskfl" };
	auto ret = Find(svec.cbegin(), svec.cend(), "asdf");
	std::cout << *ret << std::endl;

	std::list<std::string> slst = { "faasf", "dsflk", "jkl", "jfal" };
	auto result = Find(slst.cbegin(), slst.cend(), "jkl");
	std::cout << *result << std::endl;


	return 0;
}