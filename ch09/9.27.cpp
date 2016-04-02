#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;

int main()
{
	forward_list<int> iFwList = { 1, 2, 3, 5, 23, 24 };
	auto prev = iFwList.before_begin();
	auto curr = iFwList.begin();
	while (curr != iFwList.end())
	{
		if (*curr & 1)
		{
			curr = iFwList.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	for (const auto &elem : iFwList)
		cout << elem << " ";
	cout << endl;

	return 0;
}