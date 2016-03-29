#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::endl;

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}