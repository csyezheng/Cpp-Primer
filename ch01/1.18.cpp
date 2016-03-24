#include <iostream>

int main()
{
	int currVal = 0, val = 0;
	if (std::cin >> val)
	{
		int cnt = 1;
		currVal = val;
		while (std::cin >> val)
		{
			if (val == currVal)
				++cnt;
			else
			{
				std::cout << "The number of " << currVal
					<< " occur " << cnt << "times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << "The number of " << currVal
			<< " occur " << cnt << " times" << std::endl;
	}
	return 0;
}