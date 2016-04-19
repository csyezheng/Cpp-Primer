#ifndef NOTQUERY_H
#define NOTQUERY_H

#include <iostream>
#include <memory>
#include <string>
#include "Query_base.h"
#include "QueryResult.h"
#include "Query.h"

class NotQuery : public Query_base
{
	friend Query operator~ (const Query&);
	NotQuery(const Query &q) : query(q) 
	{ 
		std::cout << "NoQuery(const Query&)" << std::endl;
	}
	QueryResult eval(const TextQuery&) const;
	std::string rep() const override 
	{ 
		std::cout << "NoQuery(const Query&)" << std::endl;
		return "~(" + query.rep() + ")";
	}
	Query query;
};

inline Query operator~ (const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}


#endif