#include <iostream>

void reset(int &val)
{
	val = 0;
}

int main()
{
	int number = 100;
	int &rNum = number;
	reset(rNum);
	std::cout << number << std::endl;

	return 0;
}