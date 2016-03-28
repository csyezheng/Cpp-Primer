#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
	string word, text;
	while (cin >> word)
	{
		text += word;
	}
	unsigned cnt = 0;
	for (const auto &ch : text)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			++cnt;
	}
	cout << cnt << endl;
	return 0;
}