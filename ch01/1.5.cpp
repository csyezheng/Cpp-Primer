#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "the sum of ";
	std::cout << v1 << " and " << v2;
	std::cout << " is " << v1 + v2;
	std::cout << std::endl;
	return 0;
}