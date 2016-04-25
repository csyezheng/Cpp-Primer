#include <string>
#include "16.52.h"

int main()
{
	int i = 0;
	double d = 3.14;
	std::string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");

	return 0;
}