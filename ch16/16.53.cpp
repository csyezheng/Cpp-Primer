#include <iostream>
#include <string>
#include "16.53.h"

int main()
{
	int i = 4;
	double d = 3.0;
	char c = 'c';
	char *p = "dsjfak";
	std::string s("sdfa");
	print(std::cout, s) << std::endl;
	print(std::cout, s, i) << std::endl;
	print(std::cout, s, i, c, d, p) << std::endl;

	return 0;
}