#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using std::placeholders::_1;
int main()
{
	std::cout << "Please enter a number" << std::endl;
	int n;
	std::cin >> n;

	std::vector<int> ivec = { 3, 5, 5, 6, 15, 10 };
	auto wc = std::find_if_not(ivec.cbegin(), ivec.cend(),
		std::bind(std::modulus<int>(), n, _1));
	if (wc != ivec.cend())
		std::cout << n << " can be divided by all the numbers of vector" << std::endl;
	else
		std::cout << n << " can't be divided by all the numbers of vector" << std::endl;
	return 0;
}