#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::fill_n;

int main()
{
	vector<int> ivec = { 0, 12, 3, 43, 23, 53, 23, 243, 23 };
	fill_n(ivec.begin(), ivec.size(), 0);
	for (const auto &elem : ivec)
		cout << elem << " ";
	cout << endl;
	return 0;
}