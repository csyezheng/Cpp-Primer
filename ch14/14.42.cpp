#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using std::placeholders::_1;

int main()
{
	std::cout << "(a)" << std::endl;
	std::vector<int> ivec = { 142244, 23, 23, 23224, 32, 3323, 221 };
	auto cnt = std::count_if(ivec.begin(), ivec.end(), 
		std::bind(std::greater<int>(), _1, 1024));
	std::cout << cnt << std::endl;

	std::cout << "\n\n(b)" << std::endl;
	std::vector<std::string> svec = { "pooh", "pooh", "dsfja", "pooh", "dsjksa" };
	auto wc = std::find_if(svec.cbegin(), svec.cend(),
		std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
	std::cout << *wc << std::endl;

	std::cout << "\n\n(c)" << std::endl;
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::transform(vec.begin(), vec.end(), vec.begin(),          // it's amazing!
		std::bind(std::multiplies<int>(), _1, 2));
	for (const auto &elem : vec)
		std::cout << elem << " ";
	std::cout << std::endl;
}