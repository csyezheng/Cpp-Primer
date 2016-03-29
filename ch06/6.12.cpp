#include <iostream>

void swap(int &lhs, int &rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

int main()
{
	int num1 = 1, num2 = 99;
	int &r1 = num1, &r2 = num2;
	swap(r1, r2);

	std::cout << num1 << " " << num2 << std::endl;

	return 0;
}