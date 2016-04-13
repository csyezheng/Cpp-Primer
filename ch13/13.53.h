#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr() : ps(nullptr), i(0) { }
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) 
	{
		std::cout << "HasPtr(const HasPtr&)" << std::endl;
	}
	/*
	HasPtr &operator= (const HasPtr &rhs)
	{
		auto temp = new std::string(*rhs.ps);
		delete ps;
		ps = temp;
		i = rhs.i;
		std::cout << "HasPtr &operator= (const HasPtr&)" << std::endl;
		return *this;
	}
	*/
	HasPtr &operator= (HasPtr rhs)
	{
		swap(*this, rhs);
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
	HasPtr(HasPtr &&rhs) :ps(rhs.ps), i(std::move(rhs.i)) 
	{
		std::cout << "HasPtr(HasPtr&&)" << std::endl;
	}
	HasPtr &operator= (HasPtr &&rhs)
	{
		ps = rhs.ps;
		i = std::move(rhs.i);
		std::cout << "HasPtr &operator= (HasPtr &&)" << std::endl;
		return *this;
	}
private:
	std::string *ps;
	int i;
};


void swap(HasPtr&, HasPtr&);

#endif