#include <iostream>

int main()
{
	int i;
	double d;
	d = i = 3.5;
	std::cout << "d = i = 3.5\ni = " << i 
		<< "\nd = "<< d << std::endl;

	i = d = 3.5;
	std::cout << "i = d = 3.5\ni = " << i
		<< "\nd = " << d << std::endl;

	return 0;
}