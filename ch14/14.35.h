#ifndef PRINT_STRING_H
#define PRINT_STRING_H

#include <iostream>
#include <string>


class Print_String
{
public:
	Print_String(std::istream &input = std::cin) : is(input) { }
	std::string &operator() (std::string &line)
	{
		if (!getline(is, line))
			line = std::string();
		return line;
	}
private:
	std::istream &is;
};



#endif