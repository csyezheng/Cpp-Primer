#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;
using std::accumulate;

int main()
{
	vector<int> ivec = { 0, 1, 23, 12, 43, 23, 53, 23 };
	cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
	return 0;
}