#include <string>
#include <memory>
#include <cstddef>
#include <iostream>
#include <algorithm>

int main()
{
	std::size_t n = 0;
	std::cout << "please enter a number used to allocate memory" << std::endl;
	std::cin >> n;
	std::allocator<std::string> alloc;
	auto beg = alloc.allocate(n);
	std::string str;
	auto allocptr = beg; 
	while(std::cin >> str)
		alloc.construct(allocptr++, str);
	std::for_each(beg, allocptr,
		[](const std::string &s) { std::cout << s << std::endl; });
	while (allocptr != beg)
		alloc.destroy(--allocptr);
	alloc.deallocate(beg, n);
	return 0;
}