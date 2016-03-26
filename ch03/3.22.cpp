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
	vector<string> text;
	string line;
	while (getline(cin, line))
		text.push_back(line);

	for (auto &word : text)
	{
		for (auto &ch : word)
			if (isalpha(ch))
				ch = toupper(ch);
		cout << word;
	}
	cout << endl;

	return 0;
}