#ifndef STATISTIC_H
#define STATICTIC_H

#include <cstddef>
#include <string>

class Statistic
{
public:
	Statistic(int val) sz(val) { }
	bool operator() (const std::string &s)
	{
		return s.size() == sz;
	}
	void incr_count()
	{
		++count;
	}
	print()
	{
		std::cout << count;
	}
private:
	std::size_t sz;
	std::size_t count = 0;
};


#endif