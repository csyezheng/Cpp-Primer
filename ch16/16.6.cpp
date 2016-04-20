#include <iostream>
#include "16.6.h"

int main()
{
	int arr[] = { 1, 3, 4, 5, 2, 5, 9, 0 };
	std::cout << *Begin(arr) << std::endl;
	std::cout << *(End(arr) - 1) << std::endl;
	return 0;
}