#include <iostream>
#include <cstddef>

using namespace std;

void print(const int *cp)
{
	if (cp)
		while (*cp)
			cout << *cp++;
}

void print(const int *beg, const int *end)
{
	while (beg != end)
		cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i)
	{
		cout << ia[i] << endl;
	}
}

int main()
{
	int j[2] = { 0, 1 };
	print(j);
	print(begin(j), end(j));
	print(j, 2);
	return 0;
}