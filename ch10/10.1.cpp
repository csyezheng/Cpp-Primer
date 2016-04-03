#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::count;
using std::cin;

int main()
{
	vector<int> ivec;
	for (int val; cin >> val; ivec.push_back(val));
	cout << count(ivec.cbegin(), ivec.cend(), 9) << endl;
	return 0;
}