#include <iostream>
#include <string>
#include <forward_list>

using std::cout;
using std::endl;
using std::string;
using std::forward_list;

void insertStrToFL(forward_list<string> &sFLst,const string str1,
	const string str2)
{
	bool haveInserted = false;
	auto prev = sFLst.before_begin();
	for (auto beg = sFLst.begin(); beg != sFLst.end(); ++beg, ++prev)
	{
		if (*beg == str1)
		{
			sFLst.insert_after(beg, str2);
			haveInserted = true;
			break;
		}
	}
	if (!haveInserted)
		sFLst.insert_after(prev, str2);
}
int main()
{
	forward_list<string> fwList = { "You", "will", "a", "fun", "day" };
	insertStrToFL(fwList, "will", "have");
	for (const auto &elem : fwList)
		cout << elem << " ";
	cout << endl;
	return 0;
}