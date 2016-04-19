#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include <string>
#include "Query_base.h"
#include "QueryResult.h"
#include "WordQuery.h"
#include <iostream>

class Query
{
	friend Query operator& (const Query&, const Query&);
	friend Query operator| (const Query&, const Query&);
	friend Query operator~ (const Query&);
public:
	Query(const std::string &s): q(new WordQuery(s)) { };
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) { }
	std::shared_ptr<Query_base> q;
};

std::ostream &operator<< (std::ostream&, const Query&);

#endif