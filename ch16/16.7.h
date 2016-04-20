#ifndef CONSTEXPRE_H
#define CONSTEXPRE_H

template<typename T, unsigned N>
constexpr unsigned Size(const T(&arr)[N])
{
	return N;
}



#endif