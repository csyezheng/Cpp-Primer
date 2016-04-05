#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<std::string> uniWord;
	std::string word;
	while (std::cin >> word)
	{
		auto iter = std::find(uniWord.cbegin(), uniWord.cend(), word);
		if (iter == uniWord.cend())
			uniWord.push_back(word);
	}
	for (const auto &elem : uniWord)
		std::cout << elem << " ";
	std::cout << std::endl;
	return 0;
}