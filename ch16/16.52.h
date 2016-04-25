#ifndef FOO_H
#define FOO_H

#include <iostream>

template<typename ...Args>
void foo(Args...args)
{
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(args) << std::endl;
}




#endif