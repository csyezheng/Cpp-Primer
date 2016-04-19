#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include "QueryResult.h"

using std::shared_ptr;
using std::vector;
using std::string;
using std::set;
using std::ostream;

QueryResult::QueryResult(const string &s, shared_ptr<set<line_no>> l, shared_ptr<vector<string>> f) :
	sought(s), lines(l), file(f) { }

std::set<QueryResult::line_no>::iterator QueryResult::begin()
{
	return lines->begin();
}

std::set<QueryResult::line_no>::iterator QueryResult::end()
{
	return lines->end();
}

std::set<QueryResult::line_no>::const_iterator QueryResult::cbegin() const
{
	return lines->cbegin();
}

std::set<QueryResult::line_no>::const_iterator QueryResult::cend() const
{
	return lines->cend();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file() const
{
	return file;
}

void print_result(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs: " << qr.lines->size() 
		<< (qr.lines->size() > 1 ? "times" : "time") << std::endl;
	for (const auto &num : *qr.lines)
		os << "\t(" << num + 1 << ") " << (*qr.file)[num] << std::endl;
}

