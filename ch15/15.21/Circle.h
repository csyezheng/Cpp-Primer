#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Square.h"

class Circle : public Square
{
public:
	Circle() = default;
	Circle(const std::string &n, double r) : Square(n, 2r), radius(r) { }
	double area() const override
	{
		return 2 * 3.14 * radius * radius;
	}
protected:
	double radius = 0.0;
};


#endif