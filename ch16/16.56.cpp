#include <iostream>
#include <string>
#include "16.56.h"

int main()
{
	std::string s1("dsaf"), s2("kfkf"), s3("dsfj"), s4("kjdfa");
	errorMsg(std::cerr, s1, s2, s3, s4);

	return 0;
}