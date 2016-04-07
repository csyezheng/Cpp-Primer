#include <vector>
#include <iostream>
#include <memory>


std::shared_ptr<std::vector<int>> createVec()
{
	return std::make_shared<std::vector<int>>();
}

void readVal(std::shared_ptr<std::vector<int>> pvec)
{
	int val = 0;
	while (std::cin >> val)
		pvec->push_back(val);
}

void print(std::shared_ptr<std::vector<int>> pvec)
{
	for (const auto &elem : *pvec)
		std::cout << elem << " ";
	std::cout << std::endl;
}

int main()
{
	auto pvec = createVec();
	readVal(pvec);
	print(pvec);
	return 0;
}