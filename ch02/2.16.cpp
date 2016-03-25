int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;

	/* (a) */
	r2 = 3.14159;

	/* (b) */
	r2 = r1;  // can't let a reference bind another object

	/* (c) */
	i = r2;

	/* (d) */
	r1 = d;  // can't let a reference bind another object

	return 0;
}