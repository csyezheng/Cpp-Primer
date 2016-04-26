#ifndef MAKE_SHARED_H
#define MAKE_SHARED_H

#include <memory>

template <typename T, typename...Args>
std::shared_ptr<T> Make_shared(Args... args)    // use uppter alpha to differ from make_shared
{
	return std::shared_ptr<T>(new std::forward<Args>(args)...);
}



#endif