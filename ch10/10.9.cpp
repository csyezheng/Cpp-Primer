#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::unique;

void print(const vector<int> vec)
{
	for (const auto &elem : ivec)
		cout << elem << " ";
	cout << endl;
}
void elimDups(vector<int> &vec)
{
	sort(vec.begin(), vec.end());
	print(vec)
	auto end_unique = unique(vec.begin(), vec.end());
	print(vec);
	vec.erase(end_unique, vec.end());
	print(vec);
}

int main()
{
	vector<int> ivec;
	for (int val; cin >> val; ivec.push_back(val));
	print(ivec);
	elimDups(ivec);
	return 0;
}