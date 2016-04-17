#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
public:
	Square() = default;
	Square(const std::string &n, double a) : 
		name(n), lthOfside(a) { }
	virtual ~Square() = default;
	std::string isname() const
	{
		return name;
	}
	virtual double area() const
	{
		return lthOfside * lthOfside;
	}
private:
	std::string name;
	double lthOfside = 0.0;
};



#endif