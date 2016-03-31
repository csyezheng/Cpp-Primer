#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readWord(const string filename, vector<string> &svec)
{
	ifstream is;
	is.open(filename, ifstream::in);
	if (is)
	{
		string word;
		while (is >> word)
		{
			svec.push_back(word);
		}
	}
	else
	{
		cerr << "can't open the file" << endl;
	}
}

int main()
{
	vector<string> vec;
	readWord("book.txt", vec);
	for (const auto &word : vec)
	{
		cout << word << " ";
	}
	cout << endl;
	return 0;
}