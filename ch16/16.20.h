#ifndef PRINT_CONTAINER_H
#define PRINT_CONTAINER_H

#include <iostream>

template<typename T>
void print(const T &items)
{
	for (auto iter = items.begin(); iter != items.end(); ++iter)
		std::cout << *iter << std::endl;
}


#endif