#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <iostream>
#include <memory>
#include "Query.h"
#include "BinaryQuery.h"

class AndQuery : public BinaryQuery
{
	friend Query operator& (const Query&, const Query&);
	AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&")
	{
		std::cout << "AndQuery(const Query&, const Query&)" << std::endl;
	}
	QueryResult eval(const TextQuery&) const override;
};

inline Query operator& (const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


#endif