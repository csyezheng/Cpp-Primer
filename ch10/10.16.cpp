#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::stable_sort;
using std::unique;

void elimDups(vector<string> &vec)
{
	sort(vec.begin(), vec.end());
	auto iter = unique(vec.begin(), vec.end());
	vec.erase(iter, vec.end());
}
string make_plural(int i, const string &s1, const string &s2)
{
	return i > 1 ? s1 + s2 : s1;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1,
		const string &s2) { return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a) { return a.size() > sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< "of length " << sz << " or longer" << endl;
	std::for_each(wc, words.end(),
		[](const string &str) { cout << str << " "; });
	cout << endl;
}

int main()
{
	vector<string> words = { "the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle" };
	biggies(words, 5);
	return 0;
}