#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string()), i(0) { }
	HasPtr(const HasPtr &rhs) :
		ps(new std::string(*rhs.ps)), i(rhs.i) { }
	HasPtr &opeartor(const HasPtr &rhs)
	{
		auto newp = new std::string(*rhs.ps);
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
	}
private:
	std::string *ps;
	int i;
};

#endif