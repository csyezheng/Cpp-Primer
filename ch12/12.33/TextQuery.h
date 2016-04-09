#ifndef TEXTQUERY
#define TEXTQUERY

#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <iterator>
#include "../12.22/ConstStrBlobPtr.h"

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
	friend std::ostream &print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string &s,
		std::shared_ptr<std::set<line_no>> p,
		StrBlob f);
	std::set<line_no>::iterator begin() const;
	std::set<line_no>::iterator end() const;
	std::shared_ptr<StrBlob> get_file() const;
private:
	StrBlob file;
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
};

std::ostream &print(std::ostream &os, const QueryResult&);

#endif