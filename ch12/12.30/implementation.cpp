#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &input)
{
	string text;
	while (getline(input, text))
	{
		file->push_back(text);
		istringstream line(text);
		size_t n = file->size() - 1;
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto ret = wm.find(sought);
	if (ret == wm.cend())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, ret->second, file);
}

QueryResult::QueryResult(const string &s, shared_ptr<set<line_no>> p, shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) { }

ostream &print(ostream &os, const QueryResult &qr)
{ 
	cout << qr.sought << " occurs " << qr.lines->size() 
		<< ((qr.lines->size() > 1) ? " times" : " time") << endl;
	for (const auto &num : *qr.lines)
	{
		cout << "\t(line " << num + 1 << ") " << (*qr.file)[num] << endl;
	}
	return os;
}