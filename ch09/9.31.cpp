#include <iostream>
#include <list>
#include <forward_list>

using std::cout;
using std::endl;
using std::list;
using std::forward_list;
using std::advance;

int main()
{
	/* revise for list */
	list<int> ilst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto iter = ilst.begin(); iter != ilst.end(); /* empty */)
	{
		if (*iter % 2)
		{
			iter = ilst.insert(iter, *iter);
			advance(iter, 2);
		}
		else
		{
			iter = ilst.erase(iter);
		}
	}
	for (const auto &elem : ilst)
		cout << elem << " ";
	cout << endl;

	/* revise for forward_list */
	forward_list<int> iFwLst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto prev = iFwLst.before_begin(), iter = iFwLst.begin();
	iter != iFwLst.end(); /* empty */)
	{
		if (*iter % 2)
		{
			iter = iFwLst.insert_after(prev, *iter);
			advance(iter, 2);
			advance(prev, 2);
		}
		else
		{
			iter = iFwLst.erase_after(prev);
		}
	}
	for (const auto &entry : iFwLst)
		cout << entry << " ";
	cout << endl;

	return 0;
}