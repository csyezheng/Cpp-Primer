#include <memory>
#include <iostream>

void process(std::shared_ptr<int> ptr)
{
	
}

int main()
{
	auto p = new int();
	auto sp = std::make_shared<int>();

	/* b */
	/* c */
	//plain pointer can't convert to smart pointer

	/* d */
	//using smart pointer together with raw pointer is a bad idea.

	delete p;
}