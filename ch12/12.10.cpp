#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	std::cout << "process: shared_ptr use count " 
		<< ptr.use_count() << std::endl;
}

int main()
{
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));     // it will copy *p so increase reference count
	// then it will decrease reference count 

	return 0;
}