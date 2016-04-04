#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::string> svec = { "fsdfaga", "sefg", "wr23roin",
	"skfa", "sfsha", "dsafksfs", "dsdafhaf" };
	auto ret = std::count_if(svec.begin(), svec.end(),
		[](const std::string &str) { return str.size() > 6; });
	std::cout << ret << std::endl;
	return 0;
}