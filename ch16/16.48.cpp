#include <string>
#include <iostream>
#include "16.48.h"


int main()
{
	std::string s("hi");
	std::cout << debug_rep(s) << std::endl;
	std::cout << debug_rep(&s) << std::endl;
}