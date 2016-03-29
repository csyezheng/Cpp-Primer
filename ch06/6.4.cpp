#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::endl;
using std::cout;
using std::cerr;

void func()
{
	int val;
	if (cin >> val && val > 0)
	{
		int ret = 1;
		while (val > 1)
		{
			ret *= val--;
		}
		cout << "the result is " << ret << endl;
	}
	else
	{
		cerr << "you must input a numbers" << endl;
	}
}
