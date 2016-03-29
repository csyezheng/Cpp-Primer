#include <iostream>
#include <vector>

using namespace std;

#define NDEBUG

void printVector(vector<int> &ivec)
{
#ifndef NDEBUG
	cout << ivec.size() << endl;
#endif;
	if (!ivec.empty())
	{
		auto temp = ivec.back();
		ivec.pop_back();
		printVector(ivec);
		cout << temp << " ";
	}
}

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printVector(ivec);
	return 0;
}