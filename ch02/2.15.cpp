int main()
{
	int ival = 1.01;
	int &rvall = 1.01; //invalid
	int &rval = ival;  
	int &rval13;  // reference should be bind
}