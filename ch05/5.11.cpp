#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string word, text;
	while (cin >> word)
		text += (word + " ");
	unsigned metaAlphaCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
	for (const auto &ch : text)
	{
		switch (ch)
		{
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			++metaAlphaCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newLineCnt;
			break;
		}
	}
	cout << "the numbers of meta alpha is " << metaAlphaCnt << endl;
	cout << "the numbers of blank is " << spaceCnt << endl;
	cout << "the numbers of tab symbol is " << tabCnt << endl;
	cout << "the numbers of new line symbol is " << newLineCnt << endl;

	return 0;
}