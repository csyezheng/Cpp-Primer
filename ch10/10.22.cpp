#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

bool less_and_equal(const std::string &str, std::string::size_type sz)
{
	return str.size() <= sz;
}

int main()
{
	std::vector<std::string> svec = { "the", "quick", "red",
	"fox", "jumps", "over", "the", "slow", "red", "tutle" };
	auto cnt = std::count_if(svec.begin(), svec.end(), 
		std::bind(less_and_equal, _1, 6));
	std::cout << cnt << std::endl;
	return 0;
}