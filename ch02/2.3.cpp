#include <iostream>

int main()
{
	/* program1 */
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;  //30
	std::cout << u - u2 << std::endl;  //will be a great number.

	/* program2 */
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;  //32
	std::cout << i - i2 << std::endl;  //-32
	std::cout << i - u << std::endl;  //zero
	std::cout << u - i << std::endl;  //zero
}