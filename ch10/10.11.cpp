#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::unique;
using std::stable_sort;

void print(const vector<string> vec)
{
	for (const auto &elem : vec)
		cout << elem << " ";
	cout << endl;
}

void elimDups(vector<string> &vec)
{
	sort(vec.begin(), vec.end());
	print(vec);
	auto end_unique = unique(vec.begin(), vec.end());
	print(vec);
	vec.erase(end_unique, vec.end());
	print(vec);
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> svec;
	for (string str; cin >> str; svec.push_back(str));
	print(svec);
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(), isShorter);
	print(svec);
	return 0;
}