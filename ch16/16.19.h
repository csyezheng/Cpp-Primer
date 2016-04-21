#ifndef CONTAINER_PRINT_H
#define CONTAINER_PRINT_H

#include <iostream>

template<typename T>
void print(const T &items)
{
	using size_type = typename T::size_type;
	auto sz = items.size();
	for (size_type i = 0; i != sz; ++i)
		std::cout << items[i] << std::endl;
}







#endif