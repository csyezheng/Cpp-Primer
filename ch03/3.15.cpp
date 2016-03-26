#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::vector;

int main()
{
	string str;
	if (cin >> str)
	{
		vector<string> svec;
		svec.push_back(str);
		while (cin >> str)
			svec.push_back(str);
		for (auto &elem : svec)
			cout << elem << " ";
		cout << endl;
	}
	else
	{
		cerr << "No data" << endl;
	}
}