#include <iostream>
#include <vector>
#include <algorithm>

class CompareValue
{
public:
	CompareValue(int val) : v1(val) { }
	bool operator() (int v2)
	{
		return (v1 == v2) ? true : false;
	}
private:
	int v1;
};


int main()
{
	std::vector<int> ivec = { 0, 3, 4, 0, 0, 3, 0, 0, 3, 0 };
	std::replace_if(ivec.begin(), ivec.end(), CompareValue(0), 1);
	std::for_each(ivec.cbegin(), ivec.cend(),
		[](const int value) { std::cout << value << std::endl; });
	return 0;
}