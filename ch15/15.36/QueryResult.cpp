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

void print_result(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs: " << qr.lines->size() 
		<< (qr.lines->size() > 1 ? "times" : "time") << std::endl;
	for (const auto &num : *qr.lines)
		os << "\t(" << num + 1 << ") " << (*qr.file)[num] << std::endl;
}

