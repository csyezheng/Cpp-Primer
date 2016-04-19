#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <memory>
#include "TextQuery.h"

class QueryResult
{
	friend void print_result(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string &,
		std::shared_ptr<std::set<line_no>>,
		std::shared_ptr<std::vector<std::string>>);
	std::set<line_no>::iterator begin();
	std::set<line_no>::iterator end();
	std::set<line_no>::const_iterator cbegin() const;
	std::set<line_no>::const_iterator cend() const;
	std::shared_ptr<std::vector<std::string>> get_file() const;
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

void print_result(std::ostream&, const QueryResult&);

#endif