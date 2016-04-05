#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>

int main()
{
	std::vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> vec1, vec2;
	std::deque<int> deq3;

	std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(vec1));
	std::cout << "use back_inserter " << std::endl;
	for (const auto &elem : vec1)
		std::cout << elem << " ";
	std::cout << std::endl;

	std::copy(ivec.cbegin(), ivec.cend(), std::inserter(vec2, vec2.begin()));
	std::cout << "use inserter " << std::endl;
	for (const auto &elem : vec2)
		std::cout << elem << " ";
	std::cout << std::endl;

	std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(deq3));
	std::cout << "use front_inserter" << std::endl;
	for (const auto &elem : deq3)
		std::cout << elem << " ";
	std::cout << std::endl;

	return 0;
}