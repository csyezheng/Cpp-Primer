#ifndef FOO_H
#define FOO_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <initializer_list>;

class Foo
{
public:
	Foo sorted() &&
	{
		std::sort(data.begin(), data.end());
		std::cout << "Foo sorted() &&" << std::endl;
		return *this;
	}
	Foo sorted() const &;
private:
	std::vector<int> data;
};

#endif