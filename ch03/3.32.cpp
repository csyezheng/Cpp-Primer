#include <cstddef>
#include <vector>


using std::vector;
using std::size_t;

int main()
{
	int arr[10];
	for (size_t i = 0; i != 10; ++i)
		arr[i] = i;
	int arrCpy[10];
	for (size_t i = 0; i != 10; ++i)
		arrCpy[i] = arr[i];

	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i)
		ivec.push_back(i);
	vector<int> ivecCpy;
	for (auto &elem : ivec)
		ivecCpy.push_back(elem);

	return 0;
}