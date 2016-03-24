#include <iostream>

int main()
{
	/* exercise1.9 used for */
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;

	/* exercise1.10 used for */
	for (int i = 10; i >= 0; --i)
		std::cout << i << " ";
	std::cout << std::endl;

	/* exercise1.11 used for */
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	if (v2 < v1)
		std::swap(v1, v2);
	for (int i = v1; i <= v2; ++i)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
