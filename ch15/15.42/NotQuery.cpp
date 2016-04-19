#include <memory>
#include "NotQuery.h"

QueryResult NotQuery::eval(const TextQuery &t) const
{
	auto before = query.eval(t);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = before.cbegin(), end = before.cend();
	auto sz = before.get_file()->size();
	for (std::size_t i = 0; i != sz; ++i)
	{
		if (beg == end || *beg != i)
			ret_lines->insert(i);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, before.get_file());
}