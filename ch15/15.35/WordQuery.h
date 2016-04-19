#ifndef WORDQUERY_H
#define WORDQUERY_H

#include <string>
#include "QueryResult.h"
#include "Query_base.h"
#include "Query.h"

class WordQuery : public Query_base 
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) { }
	QueryResult eval(const TextQuery&) const;
	std::string rep() const { return query_word; }
	std::string query_word;
};




#endif