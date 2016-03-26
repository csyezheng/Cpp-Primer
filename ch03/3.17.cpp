#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string str;
	vector<string> svec;
	while (cin >> str)
		svec.push_back(str);
	for (auto &elem : svec)
	{
		for (auto &ch : elem)
			ch = toupper(ch);
		cout << elem << endl;
	}

	return 0;
}