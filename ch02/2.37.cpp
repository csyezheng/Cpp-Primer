#include <iostream>

int main()
{
	int a = 4, b = 4;
	decltype(a) c = a;  // c has a type of "int"
	decltype(a = b) d = a; // d has a type of "reference of int"

	return 0;
}