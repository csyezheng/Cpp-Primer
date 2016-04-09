#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <iterator>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &input)
{
	string text;
	while (getline(input, text))
	{
		file.push_back(text);
		size_t n = file.size() - 1;
		istringstream iss(text);
		string word;
		while (iss >> word)
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
	shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto ret = wm.find(sought);
	if (ret == wm.cend())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, ret->second, file);
}

QueryResult::QueryResult(const string &s, shared_ptr<set<line_no>> p,
	StrBlob f) : sought(s), lines(p), file(f) { }

set<QueryResult::line_no>::iterator QueryResult::begin() const
{
	return lines->begin();
}

set<QueryResult::line_no>::iterator QueryResult::end() const
{
	return lines->end();
}

shared_ptr<StrBlob> QueryResult::get_file() const
{
	return make_shared<StrBlob>(file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() <<
		((qr.lines->size() > 1) ? " times" : " time") << endl;
	for (const auto &num : *qr.lines)
	{
		ConstStrBlobPtr p(qr.file, num);
		os << "\t(line " << num + 1 << p.deref() << endl;
	}
	return os;
}