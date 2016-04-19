#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include <string>
#include "Query_base.h"


class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, const std::string &op) :
		lhs(l), rhs(r), opSym(op) { }
	std::string rep() const override { return lhs.rep() + " " + opSym + " " + rhs.rep(); }
	Query lhs, rhs;
	std::string opSym;
};


#endif