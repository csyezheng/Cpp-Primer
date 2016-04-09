#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0), use_count(new std::size_t(1)) { }
	HasPtr(const HasPtr &rhs) :
		ps(rhs.ps), i(rhs.i), use_count(rhs.use_count) 
	{
		++use_count;
	}
	HasPtr &operator= (const HasPtr &rhs)
	{
		++*rhs.use_count;
		if (--*use_count == 0)
		{
			delete ps;
			delete use_count;
		}
		ps = rhs.ps;
		i = rhs.i;
		use_count = rhs.use_count;
		return *this;
	}
	~HasPtr()
	{
		if (--*use_count == 0)
		{
			delete ps;
			delete use_count;
		}
	}
private:
	std::string *ps;
	int i;
	std::size_t *use_count;
};

#endif