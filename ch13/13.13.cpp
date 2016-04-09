#include <iostream>

struct X
{
	X()
	{
		std::cout << "X()" << std::endl;
	}
	X(const X &rhs)
	{
		std::cout << "X(const X&)" << std::endl;
	}
	X &operator= (const X &rhs)
	{
		std::cout << "X &operator= (const X&)" << std::endl;
		return *this;
	}
	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};


X fun(X item1, X &item2)  // item1 will use copy constructor, item2 will not
{
	std::cout << "-----parameter have been converted----" << std::endl;
	item1 = item2;
	std::cout << "-----assignment above-------" << std::endl;
	return item1;
}

int main()
{
	X x1, x2, x3;
	x3 = fun(x1, x2);  // fun() will create a temp X object , then destroy it
	return 0;
}