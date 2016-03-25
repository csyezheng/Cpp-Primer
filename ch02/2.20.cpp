#include <iostream>

int main()
{
	int i = 42;
	int *pl = &i;
	*pl = *pl * *pl;
	/* this program is to let i equal to  it's square */

	std::cout << *pl << std::endl;
	return 0;
}