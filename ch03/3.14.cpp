#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> ivec;
	int val;
	while (cin >> val)
		ivec.push_back(val);
	for (auto &elem : ivec)
		cout << elem << " ";
	cout << endl;
	return 0;
}