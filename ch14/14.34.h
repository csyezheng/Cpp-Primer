#ifndef FUNCTIONAL_OBJECT_H
#define FUNCTIONAL_OBJECT_H

class Functional_object
{
public:
	int operator() (bool b, int v2, int v3)
	{
		return b ? v2 : v3;
	}
};




#endif