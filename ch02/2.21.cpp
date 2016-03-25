int main()
{
	int i = 0;
	
	/* (a) */
	double *dp = &i; //Invalid, pointer's type should be the same to object

	/* (b) */
	int *ip = i; //Invalid

	/* (c) */
	int *p = &i;
}