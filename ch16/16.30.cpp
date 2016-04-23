#include <string>
#include <iostream>
#include "Header.h"
#include "16.29.h"

int main()
{
	Blob<std::string> sblob;
	std::string str("sdfk");
	sblob.push_back(str);
	sblob.push_back("fdalk");
	sblob.pop_back();
	std::cout << sblob.front() << std::endl;
	return 0;
}