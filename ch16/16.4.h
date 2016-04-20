#ifndef FIND_H
#define FIND_H

#include <iterator>

template<typename Iterator, typename T>
Iterator Find(Iterator first, Iterator last, const T &value)
{
	auto iter = first;
	for (/* */; iter != last; ++iter)                           
		if (*iter == value)
			break;
	return iter;
}




#endif