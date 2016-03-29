#include <iostream>

void changeValue(int *lhs, int *rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

int main()
{
	int num1 = 69, num2 = 96;
	int *p1 = &num1, *p2 = &num2;
	changeValue(p1, p2);
	std::cout << num1 << " " << num2 << std::endl;
}