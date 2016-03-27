#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto &elem : ivec)
	{
		if (elem % 2 == 1)
			elem *= 2;
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}