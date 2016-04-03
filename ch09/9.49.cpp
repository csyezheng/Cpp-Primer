#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::runtime_error;

string func(const string &filename)
{
	ifstream ifs("filename");
	if (!ifs)
		throw runtime_error("can't open the file.");
	string str, longest;
	while (ifs >> str)
	{
		if (string::npos == str.find_first_not_of("aceimnorstuvw"))
			longest = (longest.size() < str.size()) ? str : longest;
	}
	return longest;
}

int main()
{
	string ret = func("text.txt");
	cout << ret << endl;
	return 0;
}