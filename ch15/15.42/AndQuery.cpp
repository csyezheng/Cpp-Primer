#include <memory>
#include <iterator>
#include <algorithm>
#include "AndQuery.h"

QueryResult AndQuery::eval(const TextQuery &t) const
{
	auto left = lhs.eval(t), right = rhs.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
		std::inserter(*ret_lines, ret_lines->cbegin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
