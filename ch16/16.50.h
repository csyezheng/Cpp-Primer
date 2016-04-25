#ifndef EX_16_50_H
#define EX_16_50_H

#include <iostream>

template<typename T> void f(T);
template<typename T> void f(const T*);
template<typename T> void g(T);
template<typename T> void g(T*);


template<typename T>
void f(T t)
{
	std::cout << "void f(T)" << std::endl;
}

template<typename T>
void f(const T *p)
{
	std::cout << "void f(const T*)" << std::endl;
}

template<typename T>
void g(T t)
{
	std::cout << "void g(T t)" << std::endl;
}

template<typename T>
void g(T *p)
{
	std::cout << "void g(T *p)" << std::endl;
}





#endif