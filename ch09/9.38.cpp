#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> ivec;
	for (int i = 0; i != 20; ++i)
	{
		ivec.push_back(i);
		cout << "after push_back a value" << " ";
		cout << ivec.capacity() << endl;
	}
	return 0;
}