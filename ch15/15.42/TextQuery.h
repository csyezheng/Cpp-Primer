#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <set>

class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
	std::shared_ptr<std::vector<std::string>> file;
};



#endif