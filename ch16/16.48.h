#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <sstream>
#include <string>
#include <iostream>

template<typename T> std::string debug_rep(const T&);
template<typename T> std::string debug_rep(T*);
std::string debug(const std::string&);


template<typename T>
std::string debug_rep(const T &t)
{
	std::cout << "call debug_rep(const T&)..........." << std::endl;
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>
std::string debug_rep(T *p)
{
	std::cout << "call debug_rep(T*)................." << std::endl;
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}


std::string debug_rep(const std::string &s)
{
	std::cout << "debug(const std::string &s)" << std::endl;
	return '"' + s + '"';
}





#endif