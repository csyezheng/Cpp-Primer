#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string func(string name, const string &prev, const string &follow)
{
	name.insert(0, prev);
	name.append(follow);
	return name;
}

int main()
{
	string aname("ye");
	string ret = func(aname, "Mr.", "Jr.");
	cout << ret << endl;
	return 0;
}