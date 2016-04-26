#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <sstream>
#include <string>

template<typename T>
std::string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pinter: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " nullptr";
	return ret.str();
}

template<> 
std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}

template<>
std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}


#endif