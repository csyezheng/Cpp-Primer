#ifndef PRINT_TEMPLATE_H
#define PRINT_TEMPLATE_H

#include <iostream>

template<typename Arr>
void print(const Arr &arr)
{
	for (const auto &elem : arr)
		std::cout << elem << std::endl;
}



#endif