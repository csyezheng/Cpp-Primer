#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	/* method1 */
	vector<int> v1(10, 42);
	for (auto &elem : v1)
		cout << elem << " ";
	cout << endl;

	/* method2 */
	vector<int> v2{ 42,42,42,42,42,42,42,42,42,42 };
	for (auto &elem : v2)
		cout << elem << " ";
	cout << endl;

	/* method */
	vector<int> v3;
	for (int i = 0; i != 10; ++i)
	{
		v3.push_back(42);
		cout << v3[i] << " "
	}
	cout << endl;

	return 0;
}