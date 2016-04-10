#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "13.31.h"

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

bool HasPtr::operator< (const HasPtr &rhs)
{
	return *ps < *rhs.ps;
}

HasPtr::~HasPtr()
{
	delete ps;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
	lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	auto temp = lhs;
	return temp.operator<(rhs);
}

int main()
{
	HasPtr item1("dasfjlk"), item2("dsaflk"), item3("adaskjla");
	std::vector<HasPtr> vec = { item1, item2, item3 };
	std::sort(vec.begin(), vec.end());
	std::for_each(vec.begin(), vec.end(),
		[](const HasPtr &hp) { hp.show(); });
	return 0;
}