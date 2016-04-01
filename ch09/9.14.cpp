#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
	list<char*> clst = { "slajfk", "sfakg", "dakjag" };
	vector<string> svec;
	svec.assign(clst.cbegin(), clst.cend());
	for (const auto &elem : svec)
	{
		cout << elem << endl;
	}
	return 0;
}