#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec = { 1, 2, 4, 2, 5, 1, 7, 9, 3 };
	int arr[9];
	for (auto i = 0; i != ivec.size(); ++i)
		arr[i] = ivec[i];
	for (auto elem : arr)
		cout << elem << " ";
	cout << endl;
	return 0;
}