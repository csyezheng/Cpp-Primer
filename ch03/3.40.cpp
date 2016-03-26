#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;

int main()
{
	const char ca1[] = "The Little Fox";
	const char ca2[] = "And The Old Fox";
	constexpr size_t new_size = strlen(ca1) + strlen(" ") + strlen(ca2) + 1;
	char ca3[new_size];

	strcpy(ca3, ca1);
	strcat(ca3, " ");
	strcat(ca3, ca2);

	return 0;
}