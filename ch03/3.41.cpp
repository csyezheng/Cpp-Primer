#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
	int arr[] = { 1, 2, 4, 1, 4, 6, 2 };
	vector<int> ivec = { begin(arr), end(arr) };
	for (auto &elem : ivec)
		cout << elem << " ";
	cout << endl;
	return 0;
}