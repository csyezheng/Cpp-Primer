#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr
{
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &rhs) :
		ps(new std::string(*rhs.ps)), i(rhs.i) { }
	HasPtr &operator= (const HasPtr &rhs)
	{
		auto temp = new std::string(*rhs.ps);
		delete ps;
		ps = temp;
		i = rhs.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string *ps;
	int i;
};

#endif