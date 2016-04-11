#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include "13.42.h"

using namespace std;

TextQuery::TextQuery(ifstream &input)
{
	string text;
	while (input >> text)
	{
		file->push_back(text);
		size_t n = file->size() - 1;
		istringstream iss(text);
		string word;
		while (iss >> word)
		{
			auto lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>());   // notice
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &s)
{
	shared_ptr<set<line_no>> nodata(new set<line_no>());
	auto ret = wm.find(s);
	if (ret == wm.cend())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, ret->second, file);
}

QueryResult::QueryResult(const string &s, shared_ptr<set<line_no>> p,
	shared_ptr<StrVec> f) :sought(s), lines(p), file(f) { }

ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() 
		<< ((qr.lines->size()) ? "times" : "time") << std::endl;
	for (const auto &num : *qr.lines)
		os << "(" << num + 1 << ") " << (*qr.file)[num] << std::endl;
	return os;
}

int main()
{

}