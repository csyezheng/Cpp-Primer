#include <iostream>
#include <stdexcept>

int main()
{
	int val = 10;
	auto check_and_decrement = [&val]()
	{
		if (val < 0)
			throw std::runtime_error("Invalid error");
		return --val ? false : true;
	};
	while (!check_and_decrement())
		std::cout << val << std::endl;
	std::cout << val << std::endl;
	return 0;
		
}