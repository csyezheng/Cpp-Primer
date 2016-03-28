#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string word, text;
	while (cin >> word)
		text += word;
	unsigned cnt = 0;
	for (const auto &ch : text)
	{
		char c = tolower(ch);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			++cnt;
	}
	cout << cnt << endl;
}