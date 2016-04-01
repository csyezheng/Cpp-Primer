#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec1 = { 1, 3, 5, 7, 9 };
	vector<int> vec2 = { 1, 3, 5, 7, 11 };
	if (vec1 == vec2)
		cout << "the two vector are equal" << endl;
	else
		cout << "the two vector are not equal" << endl;

	return 0;
}