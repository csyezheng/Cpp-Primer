#include <iostream>

int main()
{
	std::cout << "/*"; // It's valid.
	std::cout << "*/"; // It's valid.
	std::cout << /* "*/" */;  // syntax error
		std::cout << "/* "* / " /* "/*" */; // It's valid;
}