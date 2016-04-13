#include <iostream>
#include "13.56.h"

Foo Foo::sorted() const &
{
	Foo ret(*this);
	std::cout << "Foo sorted() const &" << std::endl;
	return ret.sorted();      //it will caust recursion
}


int main()
{
	Foo().sorted();
	Foo f;
	f.sorted();
	return 0;
}