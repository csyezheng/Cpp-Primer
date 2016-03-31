#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void func(const string filename)
{
	ifstream is(filename);
	if (is)
	{
		string line;
		vector<string> svec;
		while (getline(is, line))
		{
			svec.push_back(line);
		}
		for (const auto &text: svec)
		{
			istringstream iss(text);
			string word;
			while (iss >> word)
				cout << word << " ";
		}
	}
	else
	{
		cerr << "can't open the file" << endl;
	}
}

int main()
{
	func("book.txt");
	return 0;
}