#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>

using std::string;

void func(const string &in_file, const string &odd_file, const string &even_file)
{
	std::ifstream ifs(in_file);
	std::istream_iterator<int> is_iter(ifs), eof;
	std::ofstream ofsOdd(odd_file), ofsEven(even_file);
	std::ostream_iterator<int> os_odd(ofsOdd, " "), 
		os_even(ofsEven, "\n");
	std::for_each(is_iter, eof,
		[&os_odd, &os_even](const int i) { (i & 0x1 ? os_odd : os_even)++ = i; });
}

int main()
{
	func("input.txt", "odd.txt", "even.txt");
	return 0;
}