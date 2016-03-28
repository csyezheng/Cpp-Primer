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
		string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
		lettergrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
	}
	return 0;
}