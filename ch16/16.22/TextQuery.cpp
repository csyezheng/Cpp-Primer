#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include "TextQuery.h"
#include "QueryResult.h"
#include "DebugDelete.h"

using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::shared_ptr;

TextQuery::TextQuery(ifstream &input) : 
	file(new vector<string>(), DebugDelete()),
	wm(new map<string, set<line_no>>(), DebugDelete())
{
	string text;
	while (getline(input, text))
	{
		file->push_back(text);
		auto n = file->size();
		istringstream iss(text);
		string word;
		while (iss >> word)
		{
			(*wm)[word].insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &word) const
{
	shared_ptr<set<line_no>> nodata(new set<line_no>());
	auto ret = wm->find(word);
	if (ret == wm->cbegin())
		return QueryResult(word, nodata, file);
	else
		return QueryResult(word, std::make_shared<set<line_no>>(ret->second), file);
}
