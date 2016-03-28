#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
	string currWord, maxWord;
	unsigned currCnt = 0, maxCnt;
	if (cin >> currWord)
	{
		++currCnt;
		maxWord = currWord;
		maxCnt = currCnt;
		string word;
		while (cin >> word)
		{
			if (word == currWord)
			{
				++currCnt;
			}
			else
			{
				if (maxCnt < currCnt)
				{
					maxCnt = currCnt;
					maxWord = currWord;
				}
				currCnt = 1;
				currWord = word;
			}
		}
		cout << maxWord << " " << maxCnt << endl;
	}
	else
	{
		cerr << "You must input a string" << endl;
		return -1;
	}
	return 0;
}