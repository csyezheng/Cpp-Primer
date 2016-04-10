#include <string>
#include <iostream>
#include "13.30.h"

HasPtr::HasPtr(const HasPtr &rhs) :
	ps(new std::string(*rhs.ps)), i(rhs.i) { }

HasPtr &HasPtr::operator= (const HasPtr &rhs)
{
	auto temp = new std::string(*rhs.ps);
	delete ps;
	ps = temp;
	i = rhs.i;
	return *this;
}

HasPtr::~HasPtr()
{
	delete ps;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, lhs.i);
	std::cout << "-----running swap function -----" << std::endl;
}


int main()
{
	HasPtr item1("item1"), item2("item2");
	swap(item1, item2);
	return 0;
}