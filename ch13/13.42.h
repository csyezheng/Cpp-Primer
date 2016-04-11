#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include "13.40.h"

class QueryResult;

class TextQuery
{
	friend class QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &s);
private:
	std::shared_ptr<StrVec> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
	friend std::ostream &print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string &s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<StrVec> file);
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<StrVec> file;
};

std::ostream &print(std::ostream&, const QueryResult&);

#endif