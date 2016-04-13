#include <iostream>
#include "13.53.h"

void swap(HasPtr &item1, HasPtr &item2)
{
	using std::swap;
	swap(item1.ps, item2.ps);
	swap(item1.i, item2.i);
}


int main()
{
	HasPtr hp1("a"), hp2("b"), hp3("c");
	hp1 = hp2;
	std::cout << "---------" << std::endl;
	//hp1 = std::move(hp3);
	return 0;
}