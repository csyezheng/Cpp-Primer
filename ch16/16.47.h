#ifndef FLIPL_H
#define FLIPL_H

#include <iostream>
#include <utility>

void f(int v1, int &v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

template<typename F, typename T1, typename T2>
void flipl(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}





#endif