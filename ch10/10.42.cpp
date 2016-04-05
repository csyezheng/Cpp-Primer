#include <list>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::list<std::string> slst = { "the", "quick", "red", "jumps",
	"over", "the", "slow", "red", "turtle" };

	slst.sort();
	slst.unique();
	
	for (const auto &elem : slst)
		std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}