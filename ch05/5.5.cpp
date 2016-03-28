#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

int main()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	unsigned grade;
	while (cin >> grade)
	{
		if (grade > 100)
		{
			cerr << "the number you input is invalid" << endl;
			return -1;
		}
		string lettergrade;
		if (grade < 60)
			lettergrade = scores[0];
		else
		{
			lettergrade = scores[(grade - 50) / 10];
			if (grade != 100)
			{
				if (grade % 10 > 7)
					lettergrade += '+';
				else if (grade % 10 < 3)
					lettergrade += '-';
			}
		}
		cout << lettergrade << endl;
	}
	return 0;
}