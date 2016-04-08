#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <memory>

class QueryResult;

class TextQuery
{
public:
	friend class QueryResult;
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &input);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
	friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string &s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f);
private:
	std::string sought;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<line_no>> lines;
};

std::ostream &print(std::ostream &os, const QueryResult &qr);

#endif