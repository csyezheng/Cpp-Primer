#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>::const_iterator beg, 
	vector<int>::const_iterator end)
{
	if (beg != end)
	{
		cout << *beg << endl;
		printVector(++beg, end);
	}
}

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printVector(ivec.cbegin(), ivec.cend());
	return 0;
}