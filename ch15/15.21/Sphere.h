#ifndef SPHERE_H
#define SPHERE_H

#include <string>
#include "Circle.h"

class Sphere : public Circle
{
public:
	Sphere() = default;
	Sphere(const std::string &n, double r) : Circle(n, r) { }
	double area() const override
	{
		return 4 / 3 * 3.14 * radius * radius;
	}
	virtual double bulk() const
	{
		return 3 / 4 * 3.14 * radius * radius * radius;
	}
};


#endif