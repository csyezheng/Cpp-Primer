#include <iostream>

int main()
{
	/* the same between auto and decltype */
	int v1 = 32, *v2 = &v1;
	auto v3 = v1;
	decltype(v1) v4 = v1;

	/* the difference between auto and decltype */
	/* 1 */
	auto p1 = *v2;  // p1 is int 
	decltype(*v2) p2 = *v2;  //p2 is a reference of int
	/* 2 */
	auto val = v1 + *v2;
	decltype((v1)) val2 = v1;  // val2 is a reference of int 

	return 0;
}