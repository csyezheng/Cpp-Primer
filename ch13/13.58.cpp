#include <iostream>
#include <algorithm>
#include "13.56.h"

Foo Foo::sorted() const &
{
	std::cout << "Foo sorted() const &" << std::endl;
	return Foo(*this).sorted();
}

int main()
{
	Foo().sorted();
	Foo f;
	f.sorted();
	return 0;
}