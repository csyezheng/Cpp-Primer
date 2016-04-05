#include <vector>
#include <string>
#include <utility>
#include <iostream>

int main()
{
	std::vector<std::pair<std::string, int>> pvec;
	std::string str;
	int val;
	while (std::cin >> str >> val)
	{
		pvec.push_back(std::make_pair(str, val));
		//pvec.push_back(std::pair<std::string, int>(str, val));
		//pvec.push_back({ str, val });
		//pvec.emplace_back(str, val);
	}
	for (const auto &entry : pvec)
		std::cout << entry.first << " " << entry.second << std::endl;
	return 0;
}