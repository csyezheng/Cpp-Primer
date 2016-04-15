#ifndef STATISTIC2_H
#define STATICTIC2_H

#include <cstddef>
#include <string>

class Statistic
{
public:
	Statistic(int v1, int v2) : lower(v1), upper(v2) { }
	bool operator() (const std::string &s)
	{
		std::size_t sz = s.size();
		return sz >= lower && sz < upper;
	}
private:
	std::size_t lower;
	std::size_t upper;
};


#endif