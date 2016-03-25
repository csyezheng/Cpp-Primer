#include <iostream>

struct Foo { /* */}    // C2686 C3874 C2440
						//'Foo' followed  by 'int' is illegal
int main()
{
	return 0;
}