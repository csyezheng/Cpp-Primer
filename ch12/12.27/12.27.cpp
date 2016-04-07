#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(const string &infile)
{
	ifstream input(infile);
	if (!input)
		throw runtime_error("can't open the file");
	string line;
	std::size_t lino = 0;
	while (getline(input, line))
	{
		file->push_back(line);
		istringstream iss(line);
		++lino;
		string word;
		while (iss >> word)
		{
			(*dict)[word].insert(lino);
		}
	}
}

QueryResult TextQuery::query(const std::string &find_word) const
{
	auto ret = find(dict->cbegin(), dict->cend(), find_word);
	if (ret == dict->cend())
		return QueryResult(find_word);
	else
		return QueryResult(find_word, ret, )
}