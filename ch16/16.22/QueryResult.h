#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include "TextQuery.h"

class QueryResult
{
	friend std::ostream &print(std::ostream &, const QueryResult&);
public:
	using line_no = TextQuery::line_no;
	QueryResult(const std::string &s,
		std::shared_ptr<std::set<line_no>> l,
		std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(l), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};


std::ostream &print(std::ostream &, const QueryResult&);



#endif