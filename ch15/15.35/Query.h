#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <memory>
#include <string>
#include "Query_base.h"
#include "QueryResult.h"

class Query
{
	friend Query operator& (const Query&, const Query&);
	friend Query operator| (const Query&, const Query&);
	friend Query operator~ (const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery &t) { return q->eval(); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) { }
	std::shared_ptr<Query_base> q;
};

std::ostream &operator<< (std::ostream&, const Query&);

#endif