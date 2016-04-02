#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;


int main()
{
	list<int> lst = { 1, 3, 5, 7, 9 };
	vector<int> vec = { 1, 3, 5, 8, 9 };
	vector<int> vecFromLst(lst.cbegin(), lst.cend());
	
	if (vec == vecFromLst)
	{
		cout << "the list and the vector have the same elements " << endl;
	}
	else
	{
		cout << "the list and the vector are difference" << endl;
	}

	return true;
}