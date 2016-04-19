nclude <fstream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include "TextQuery.h"
#include "QueryResult.h"

using std::ifstream;
using std::string;
using std::map;
using std::set;
using std::shared_ptr;
using std::istringstream;

TextQuery::TextQuery(ifstream &ifs)
{
	string text;
	while (getline(ifs, text))
	{
		file->push_back(text);
		line_no n = file->size();
		string word;
		istringstream iss(text);
		while (iss >> word)
		{
			auto lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>());
			lines->insert(n);
		}
	}
}


QueryResult TextQuery::query(const std::string &s) const
{
	auto nodata = std::make_shared<set<line_no>>();
	auto ret = wm.find(s);
	if (ret == wm.cend())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, (*ret).second, file);
}