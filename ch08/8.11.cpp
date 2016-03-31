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

int main()
{
	string line, word;
	vector<PersonInfo> people;
	while (std::getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);    // if move the definition of record outside the while
		record >> info.name;           // record.str(line) can't work well
		while (record >> word)         // it can't print all the record
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for (const auto &person : people)
	{
		cout << person.name << " ";
		for (const auto &phone : person.phones)
		{
			cout << phone << " ";
		}
		cout << endl;
	}

	return 0;
}