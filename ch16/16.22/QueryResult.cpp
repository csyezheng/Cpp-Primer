#include <iostream>
#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << ((qr.lines->size() > 1) ? "times" : "time") << std::endl;
	for (const auto &num : *qr.lines)
		os << "\t(" << num + 1 << ") " << (*qr.file)[num] << std::endl;
	return os;
}

int main()
{

}