#include <string>

using std::string;

bool find(string str)
{
	for (auto ch : str)
		if (ch == 'z')
			return true;
	return false;
}
int main()
{
	string s;
	string::iterator iter = s.begin();
	while ( iter != s.end()) { /* */ }

	string word;
	while (bool status = find(word))
		if (!status) { /* */}

	return 0;
}