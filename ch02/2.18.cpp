#include <iostream>

int main()
{
	int val = 8, number = 10;
	int *p1 = &val, *p2 = &number;

	/* change the pointer's value */
	p1 = p2;

	/* change the object's value by pointer */
	*p2 = 6;

	std::cout << *p1 << " " << *p2 << std::endl;
	return 0;
}