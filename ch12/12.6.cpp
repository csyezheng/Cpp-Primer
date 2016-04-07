#include <iostream>
#include <vector>

std::vector<int> *createVec()
{
	auto pvec = new std::vector<int>();
	return pvec;
}

void readVal(std::vector<int> *pvec)
{
	int val = 0;
	while (std::cin >> val)
		pvec->push_back(val);
}

void print(std::vector<int> *pvec)
{
	for (const auto &elem : *pvec)
		std::cout << elem << " ";
	std::cout << std::endl;
	delete pvec;
	pvec = nullptr;
}

int main()
{
	auto pvec = createVec();
	readVal(pvec);
	print(pvec);
	return 0;
}