#include <iostream>

using std::cout;
using std::endl;

int main()
{
	auto f = [](const int v1, const int v2) { return v1 + v2; };
	cout << f(3, 2) << endl;
	return 0;
}