#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <stdexcept>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &input)
{
	string text;
	while (getline(input, text))
	{
		file.push_back(text);
		size_t n = file.size() - 1;
		istringstream line(text);
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

QueryResult TextQuery::query(const string &str) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto p = wm.find(str);
	if (p == wm.cend())
		return QueryResult(str, nodata, file);
	else
		return QueryResult(str, p->second, file);
}

QueryResult::QueryResult(const std::string &s,
	shared_ptr<set<line_no>> p, StrBlob f) : sought(s), lines(p), file(f) { }

ostream &print(ostream &os, const QueryResult &qr)
{
	cout << qr.sought << " occurs " << qr.lines->size()
		<< ((qr.lines->size() > 1) ? " times" : " time") << endl;
	for (const auto &num : *qr.lines)
	{
		ConstStrBlobPtr p(qr.file, num);
		cout << "\t(line " << num + 1 << ") " << p.deref()  << endl;
	}
	return os;
}