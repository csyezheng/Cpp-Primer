#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	std::vector<int> vec = { 1, 2, 4, 5, 2, 6, 2 };

	cout << *vec.begin() << endl;
	cout << *(vec.begin()) << endl;

	cout << *vec.begin() + 1 << endl;
	cout << (*(vec.begin())) + 1 << endl;

	return 0;
}