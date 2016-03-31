#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cerr;

void readData(const string &fileName, vector<string> &svec)
{
	ifstream ifs;
	ifs.open(fileName, ifstream::in);
	if (ifs)
	{
		string str;
		while (std::getline(ifs, str))
		{
			svec.push_back(str);
		}
	}
	else
		cerr << "can't open the file" << endl;
}

int main()
{
	vector<string> svec;
	readData("text.txt", svec);
	for (const auto &elem : svec)
	{
		cout << elem << endl;
	}
	return 0;
}