#include <iostream>
#include <string>
#include <vector>
#include "Compute.h"

using std::vector; 
using std::cout;

vector<fp*> v{ NumAdd, NumSub, NumMul, NumDiv };

int main()
{
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		cout << (*it)(2, 2) << std::endl;

	return 0;
}
