#include <iostream>

using std::cout;

void swapPtr(int *&p1, int *&p2)
{
	auto temp = p1;
	p1 = p2;
	p2 = temp;
}

int main()
{
	int val = 2, num = 3;
	int *pval = &val, *pnum = &num;
	swapPtr(pval, pnum);
	cout << *pval << " " << *pnum;
	return 0;
}