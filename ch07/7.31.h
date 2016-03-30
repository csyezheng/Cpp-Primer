#ifndef XY_H
#define XY_H

struct Y;

struct X
{
	Y *py = nullptr;
};

struct Y
{
	X x;
};



#endif