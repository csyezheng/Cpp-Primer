#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr&);
	HasPtr &operator=(const HasPtr&);
	bool operator<(const HasPtr&);
	~HasPtr();
	void swap(HasPtr &rhs)
	{
		using std::swap;
		swap(ps, rhs.ps);
		swap(i, rhs.i);
		std::cout << "swap" << std::endl;
	}
	void show() const
	{
		std::cout << *ps << std::endl;
	}
private:
	std::string *ps;
	int i;
};

void swap(HasPtr&, HasPtr&);
bool operator<(const HasPtr &lhs, const HasPtr &rhs);

#endif