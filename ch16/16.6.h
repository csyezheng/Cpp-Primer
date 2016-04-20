#ifndef BEGIN_END_H
#define BEGIN_END_H

template<typename T, unsigned N>
T *Begin(T(&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
T *End(T(&arr)[N])
{
	return arr + N;
}


#endif