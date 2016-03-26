#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl; using std::cin;
using std::cerr;

int main()
{
	int val;
	vector<int> ivec;
	while (cin >> val)
		ivec.push_back(val);
	if (ivec.size() < 2)
	{
		cerr << "The numbers of you input must be greater than 2" << endl;
		return -1;
	}
	for (auto beg = ivec.cbegin(); beg + 1 < ivec.cend(); beg += 2)
		cout << *beg + *(beg + 1) << " ";
	if (ivec.size() % 2 == 1)
		cout << *(ivec.end() - 1);
	cout << endl;
	
	/*
	int number;
	vector<int> vec;
	while (cin >> number)
		vec.push_back(number);
	if (vec.size() < 2)
	{
		cerr << "The numbers of you input must be greater than 2" << endl;
		return -1;
	}
	for (auto lhs = vec.cbegin(), rhs = vec.cend() - 1; lhs < rhs; ++lhs, --rhs)
		cout << *lhs + *rhs << " ";
	if (vec.size() % 2 == 1)
		cout << vec[vec.size() / 2];
	cout << endl;
	*/
	return 0;
}
