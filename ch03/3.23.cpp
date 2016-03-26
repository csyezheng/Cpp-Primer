#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto beg = ivec.begin(); beg != ivec.end(); ++beg)
		*beg *= 2;
	for (auto &elem : ivec)
		cout << elem << " ";
	cout << endl;
	return 0;
}