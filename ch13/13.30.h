#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr&);
	HasPtr &operator= (const HasPtr&);
	~HasPtr();
private:
	std::string *ps;
	int i;
};

void swap(HasPtr&, HasPtr&);


#endif