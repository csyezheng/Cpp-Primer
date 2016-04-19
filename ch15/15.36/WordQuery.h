#ifndef WORDQUERY_H
#define WORDQUERY_H

#include <iostream>
#include <string>
#include "QueryResult.h"
#include "Query_base.h"
#include "Query.h"

class WordQuery : public Query_base 
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) 
	{
		std::cout << "WordQuery(const string&)" << std::endl;
	}
	QueryResult eval(const TextQuery&) const override;
	std::string rep() const 
	{ 
		std::cout << "WordQuery::ret()" << std::endl;
		return query_word; 
	}
	std::string query_word;
};




#endif