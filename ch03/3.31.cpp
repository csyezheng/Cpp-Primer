#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

int main()
{
	int arr[10];
	std::size_t i = 0;
	for (auto &elem : arr)
	{
		elem = i;
		cout << arr[i] << endl;
		++i;
	}
	return 0;
}