#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> vec)
{
	sort(vec.begin(), vec.end());
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
}

string make_plural(int i, const string &s1, const string &s2)
{
	return i > 1 ? s1 + s2 : s1;
}

void biggies(vector<string> &vec, vector<string>::size_type sz)
{
	elimDups(vec);
	stable_sort(vec.begin(), vec.end(), [](const string &s1,
		const string &s2) { return s1.size() < s2.size(); });
	auto wc = stable_partition(vec.begin(), vec.end(),
		[sz](const string &str) { return str.size() < sz; });
	auto count = vec.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	for_each(wc, vec.end(), [](const string &str) { cout << str << " "; });
}

int main()
{
	vector<string> words = { "the", "quick", "over", "quick", "jumps",
	"red", "slow", "the", "turtle" };
	biggies(words, 5);
	return 0;
}