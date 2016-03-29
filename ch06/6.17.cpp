#include <iostream>
#include <string>

using namespace std;

bool haveUpperAlpha(const string &s)
{
	for (auto beg = s.cbegin(); beg != s.end(); ++beg)
		if (isupper(*beg))
			return true;
	return false;
}

void upperToLower(string &s)
{
	for (auto beg = s.begin(); beg != s.end(); ++beg)
		if (isupper(*beg))
			*beg = tolower(*beg);
}

int main()
{
	return 0;
}