#include <iostream>

int main()
{
	int a = 3, b = 4;
	decltype(a) c = a;  // c has type of "int"
	decltype((b)) d = a;  // d has type of "reference of int"
	++c;  
	++d;

	//a = 4, b = 4, c = 4, d = 4 while the program is finished
	std::cout << "a = " << a << " b = " << b
		<< " c = " << c << " d = " << d << std::endl;
	return 0;
}