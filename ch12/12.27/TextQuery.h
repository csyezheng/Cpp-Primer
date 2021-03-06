#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &word) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
	friend std::ostream &print(std::ostream&, const QueryResult&);
public:
	QueryResult::QueryResult(const std::string &s, 
		std::shared_ptr<std::set<TextQuery::line_no>> p,
		std::shared_ptr<std::vector<std::string>> f);
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream &print(std::ostream&, const QueryResult&);


#endif