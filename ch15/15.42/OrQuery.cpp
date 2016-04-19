#include <memory>
#include "OrQuery.h"


QueryResult OrQuery::eval(const TextQuery &t) const
{
	auto left = lhs.eval(t), right = rhs.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.cbegin(), left.cend());
	ret_lines->insert(right.cbegin(), right.cend());
	return QueryResult(rep(), ret_lines, left.get_file());
}
