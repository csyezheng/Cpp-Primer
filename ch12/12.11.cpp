#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	//some operation
}

int main()
{
	std::shared_ptr<int> p;

	process(std::shared_ptr<int>(p.get()));  // temperate construct
											 // reference can't be increased
											 // but it's memory will be deleted
							// so the shared_ptr above will be delete twice 
							// cause bug

	return 0;

}