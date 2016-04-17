#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"


void debug(const Quote &entry)
{
	entry.debug();
}

int main()
{
	Quote item1("jfsal", 34);
	Bulk_quote item2("fsafj", 22, 10, 0.3);
	Limit_quote item3("jfaskg", 55, 30, 0.5);

	debug(item1);
	debug(item2);
	debug(item3);

	return 0;
}