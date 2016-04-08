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

TextQuery::TextQuery(ifstream &input) : file(new vector<string>)
{
	string line;
	while (getline(input, line))
	{
		file->push_back(line);
		int n = file->size() - 1;
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			auto &lines = wm[word];
			if (lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
} 

QueryResult TextQuery::query(const std::string &word) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto ret = wm.find(word);
	if (ret == wm.cend())
		return QueryResult(word, nodata, file);
	else
		return QueryResult(word, ret->second, file);
}

QueryResult::QueryResult(const string &s, shared_ptr<set<TextQuery::line_no>> p,
	shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) { }

ostream &print(ostream& os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< ((qr.lines->size() > 1) ? "times" : "time") << std::endl;
	for (const auto &num : *qr.lines)
	{
		os << "\tline " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}