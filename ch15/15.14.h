#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class base
{
public:
	std::string name() { return basename; }
	virtual void print(std::ostream &os) { os << basename; }
private:
	std::string basename = std::string("basename");
};

class derived : public base
{
public:
	void print(std::ostream &os)
	{
		base::print(os);
		os << " " << i;
	}
private:
	int i = 0;
};


#endif