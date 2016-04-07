#include <memory>

int main()
{
	int ix = 1042, *pi = &ix, *pi2 = new int(2048);
	typedef std::unique_ptr<int> IntP;

	// unique_ptr must be initialized by a pointer allocated using new

	//  * (c) *
	IntP p2(pi2);  //when p2 goes out of scope, the raw pointer pi2 can't be used
					//it runs well, but dangerous
	
					
	// * (e) *
	IntP p4(new int(2038));   //recommended

	return 0;
}