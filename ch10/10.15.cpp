#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int v1 = 0;
	auto f = [v1](int v2) { return v1 + v2; };
	cout << f(8) << endl;
	return 0;
}