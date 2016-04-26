#ifndef STATISTIC_H
#define STATISTIC_H

#include <vector>

template<typename T>
std::size_t  count(const std::vector<T> &vec, T value)
{
	std::size_t cnt = 0;
	for (auto const& elem : vec)
		if (value == elem) 
			++cnt;
	return cnt;
}


template<>
std::size_t count(const std::vector<const char*> &vec, const char* value)
{
	std::size_t cnt = 0;
	for (const auto &elem : vec)
		if (elem == value) 
			++cnt;
	return cnt;
}

#endif