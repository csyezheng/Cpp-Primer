#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <string>
#include "Circle.h"

class Circular : public Circle
{
public:
	Circular() = default;
	Circular(const std::string &n, double r, double h) : 
		Circle(n, r), height(h) { }
	double area() const override
	{
		return 1; ///////////////////////////////// Orz...I fogot the fomula
	}
	double bulk() const 
	{
		auto Cir_area = Circle::area();
		return 0.33 * Cir_area * height;
	}
private:
	double height;
};



#endif