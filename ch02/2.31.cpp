int main()
{
	/* exercise2.30 */
	const int v2 = 0;
	int v1 = v2, i; 
	int *p1 = &v1, &r1 = v1; 
	const int *p2 = &v2, *const p3 = &i, &r2 = v2;

	/* exercise2.31 */
	r1 = v2;
	p1 = p2;  //a value of type "const int*" can't be assigned to the entity of type "int"
	p2 = p1;
	p1 = p3; //a value of type "const int" can't be assigned to the entity of type "int"
	p2 = p3;
}