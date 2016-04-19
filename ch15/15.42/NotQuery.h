#ifndef NOTQUERY_H
#define NOTQUERY_H

#include <memory>
#include <string>
#include "Query_base.h"
#include "QueryResult.h"
#include "Query.h"

class NotQuery : public Query_base
{
	friend Query operator~ (const Query&);
	NotQuery(const Query &q) : query(q) { }
	QueryResult eval(const TextQuery&) const;
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	Query query;
};

inline Query operator~ (const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}


#endif