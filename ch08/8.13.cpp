#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PersonInfo.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;

bool valid(const string &str)
{
	return isdigit(str[0]);
}

string format(const string &str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}


int main()
{
	string line, word;
	vector<PersonInfo> people;
	while (std::getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);    
		record >> info.name;           
		while (record >> word)         
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for (const auto &entry : people)
	{
		ostringstream formatted, badnum;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
				badnum << " " << nums;
			else
				formatted << " " << format(nums);
		}
		if (badnum.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cout << "Input error: " << entry.name
			<< "invalid numbers " << badnum.str() << endl;
	}

	return 0;

	return 0;
}