#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::unique;
using std::stable_sort;

class noLessThan
{
public:
	noLessThan(vector<string>::size_type i) : sz(i) { }
	bool operator() (const string &s1, const string &s2)
	{
		return s1.size() < s2.size();
	}
	bool operator() (const string &str)
	{
		return str.size() >= sz;
	}
private:
	vector<string>::size_type sz = 0;
};

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), noLessThan(sz));
	auto wc = find_if(words.begin(), words.end(), noLessThan(sz));
	auto cnt = words.end() - wc;
	cout << cnt << ((cnt > 1) ? " words": " word") << " of length "
		<< sz << " or longer" << endl;
	std::for_each(wc, words.end(), [](const string &s) { cout << s << endl; });
}

int main()
{
	vector<string> vec = { "asffsf", "dfaga", "d", "ds", "saffg" };
	biggies(vec, 4);
	return 0;
}