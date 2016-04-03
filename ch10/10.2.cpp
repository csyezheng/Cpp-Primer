#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::count;
using std::vector;

int main()
{
	vector<string> svec;
	for (string str; cin >> str; svec.push_back(str));
	cout << count(svec.cbegin(), svec.cend(), "the") << endl;
	return 0;
}