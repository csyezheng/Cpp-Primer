#include <iostream>
#include <string>
#include "16.39.h"

int main()
{
	std::cout << compare<std::string>("hello ", "world") << std::endl;
	std::cout << compare<char[5]>("mixi", "mixi") << std::endl;
	return 0;
}