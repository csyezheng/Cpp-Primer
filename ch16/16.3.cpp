#include <iostream>
#include "../ch14/Sales_data.h"
#include "16.3.h"

int main()
{
	Sales_data item1("1409140"), item2("239812409");
	int ret = compare(item1, item2);        // binary'<': no operator found
	std::cout << ret << std::endl;
	return 0;
}