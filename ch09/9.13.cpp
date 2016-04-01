#include <vector>
#include <list>
#include <iostream>

using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<double> dvec1(lst.cbegin(), lst.cend());

	for (const auto &entry : dvec1)
	{
		cout << entry << " ";
	}
	cout << endl;

	vector<int> ivec = { 0, 2, 4, 6, 8, 10 };
	vector<double> dvec2(ivec.cbegin(), ivec.cend());

	for (const auto &elem : dvec2)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;


}