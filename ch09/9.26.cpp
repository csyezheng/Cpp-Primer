#include <iostream>
#include <vector>
#include <list>

using std::iostream;
using std::vector;
using std::list;
using std::begin;
using std::end;
using std::cout;
using std::endl;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> ivec(ia, end(ia));
	list<int> ilst(ia, end(ia));

	for (auto beg = ivec.begin(); beg != ivec.end(); /* empty */)
	{
		if (!(*beg & 0x1))
			beg = ivec.erase(beg);
		else
			++beg;             
	}
	
	for (const auto &entry : ivec)
		cout << entry << " ";
	cout << endl;

	for (auto beg = ilst.begin(); beg != ilst.end(); /* empty */)
	{
		if (*beg & 0x1)
			beg = ilst.erase(beg);
		else
			++beg;
	}
	for (const auto &elem : ilst)
		cout << elem << " ";
	cout << endl;
	return 0;
}