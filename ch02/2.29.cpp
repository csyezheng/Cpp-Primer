#include <iostream>

int main()
{
	/* exercise2.28 */
	int i, *const cp; //const variable requires an initializer
	int *p1, *const p2; //const variable requires an initializer
	const int ic, &r = ic; // const variable requires an initializer
	const int *const p3; // const variable requires an initializer
	const int *p;

	/* exercise2.29 */
	i = ic; //invalid
	p1 = p3;  // "const int" can't be assigned to an entity of type "int"
	p1 = &ic; // the same to above
	p3 = &ic;  //const pointer can't be assigned value again
	p2 = pl;  // the same above
	ic = *p3;  //const obeject can't be assigned value again

}