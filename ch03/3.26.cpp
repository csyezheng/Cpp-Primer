#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::vector;

int main()
{
	vector<int> ivec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto beg = ivec.cbegin(), end = ivec.cend();
	auto mid = beg + (end - beg) / 2;
	cout << "input number what you want to search between 0 and 9" << endl;
	int sought;
	cin >> sought;
	if (sought < 0 || sought > 9)
		cerr << "the number you input is false" << endl;
	
	while(*mid != sought && mid != end)
	{
		if (sought < *mid)
			end = mid;
		else
			beg = mid;
		mid = beg + (end - beg) / 2;
	}
	cout << *mid << endl;
	return 0;
}