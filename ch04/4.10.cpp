#include <iostream>

using std::cin;

int main()
{
	int val;
	while (cin >> val && val != 42);
	std::cout << val << std::endl;
	return 0;
}