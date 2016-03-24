#include <iostream>

int main()
{
	std::cout << "Please enter two numbers!" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	if (v2 < v1)
	{
		std::swap(v1, v2);
	}
	int current = v1;
	std::cout << "the numbers between " << v1 << " and "
		<< v2 << " is: " << std::endl;
	while (current <= v2)
	{
		std::cout << current << " ";
		++current;
	}
	std::cout << std::endl;
	return 0;
}