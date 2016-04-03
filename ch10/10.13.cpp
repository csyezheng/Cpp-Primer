#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::partition;

bool longerFive(const string &str)
{
	return str.size() < 5;
}

int main()
{
	vector<string> words = { "the", "quick", "red", "fox",
	"jumps", "over", "the", "slow", "red", "turtle" };
	auto iter = partition(words.begin(), words.end(), longerFive);
	for (/* */; iter != words.end(); ++iter)
		cout << *iter << " ";
	return 0;
}