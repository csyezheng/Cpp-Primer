#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include "StrBlob.h"

class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &str) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
	friend std::ostream &print(std::ostream &, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string &s,
		std::shared_ptr<std::set<line_no>> p, StrBlob f);
private:
	StrBlob file;
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
};

std::ostream &print(std::ostream &os, const QueryResult&);

#endif