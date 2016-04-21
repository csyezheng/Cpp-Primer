#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <string>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <memory>

class QueryResult;

class TextQuery
{
	friend class QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::map<std::string, std::set<line_no>>> wm;
	std::shared_ptr<std::vector<std::string>> file;
};




#endif