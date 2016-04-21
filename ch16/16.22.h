#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include "16.21.h"

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
private:
	std::map<std::string, std::set<line_no>> wm;
	std::shared_ptr<std::vector<std::string>> file;
};




#endif