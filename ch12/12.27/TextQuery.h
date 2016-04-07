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
	friend class QueryResult;
	TextQuery() = default;
	TextQuery(const std::string &infile);
	QueryResult query(const std::string &word) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::map<std::string, std::set<std::size_t>>> dict;
};

class QueryResult
{
public:
	void print() const;
private:
	std::weak_ptr<std::vector<std::string>> wlines;
	std::weak_ptr<std::map<std::string, std::set<std::size_t>>> wdict;
};

#endif