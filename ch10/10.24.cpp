#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std::placeholders;

bool check_size(int i, std::string::size_type sz)
{
	return i > sz;
}

int main()
{
	std::string str("sgakgaga");
	std::vector<int> ivec = { 0, 1, 3, 2, 4, 9, 5, 11, 23 };
	auto iter = std::find_if(ivec.begin(), ivec.end(),
		std::bind(check_size, _1, str.size()));
	std::cout << *iter << std::endl;
	return 0;
}