#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

int main()
{
	int val;
	if (cin >> val)
	{
		vector<int> ivec;
		ivec.push_back(val);
		int num;
		while (cin >> num)
			ivec.push_back(num);
		for (auto i = 0; i != ivec.size(); i += 2)
		{
			cout << ivec[i] + ivec[i + 1] << " ";
		}
		cout << endl;
	}
	else
	{
		cerr << "No data" << endl;
	}

	/* 
	int number = 0;
	if (cin >> number)
	{
		vector<int> vec;
		vec.push_back(number);
		int curr;
		while (cin >> curr)
			vec.push_back(curr);
		vector<int>::size_type sz = vec.size();
		for (auto i = 0; i != sz / 2; ++i)
		{
			cout << vec[i] + vec[sz - i] << " ";
		}
		if (sz % 2 == 1)
			cout << vec[sz/2 + 1];
		cout << endl;
	}
	else
	{
		cerr << "No data" << endl;
	}
	*/

	return 0;
}