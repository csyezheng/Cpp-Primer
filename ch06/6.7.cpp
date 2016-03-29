#include <iostream>

using std::cout;
using std::endl;

int func()
{
	static int ret = 0;
	return ret++;
}

int main()
{
	cout << "first " << func() << endl;
	cout << "second " << func() << endl;
	cout << "third " << func() << endl;

	return 0;
}