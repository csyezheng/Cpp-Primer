#include <iostream>
#include "15.14.h"

int main()
{
	std::cout << "-----(a) (b) ------------" << std::endl;
	base bobj;
	derived dobj;
	bobj.print(std::cout);
	std::cout << std::endl;
	dobj.print(std::cout);
	std::cout << std::endl;

	std::cout << "------- (c) (d) ------" << std::endl;
	base *bp1 = &bobj;
	base *bp2 = &dobj;
	std::cout << bp1->name() << std::endl;
	std::cout << bp2->name() << std::endl;

	std::cout << "------(e) (f)--------" << std::endl;
	base &br1 = bobj;
	base &br2 = dobj;
	br1.print(std::cout);
	std::cout << std::endl;
	br2.print(std::cout);
	std::cout << std::endl;

}