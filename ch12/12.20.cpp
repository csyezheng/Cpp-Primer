#include <iostream>
#include <string>
#include "12.19/StrBlob.h"

int main()
{
	StrBlob sb;
	std::string str;
	while (std::cin >> str)
	{
		sb.push_back(str);
	}
	for (StrBlobPtr beg(sb.begin()), end(sb.end()); beg != end; beg.incr())
	{
		std::cout << beg.deref() << std::endl;
	}
	return 0;
}