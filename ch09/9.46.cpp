#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string func(string name, const string &prev, const string &follow)
{
	name.insert(0, prev);
	name.insert(name.size(), follow);
	return name;
}

int main()
{
	string name("ye");
	string ret = func(name, "Mr.", "Jr.");
	cout << ret << endl;
	return 0;
}