int main()
{
	const int buf; //const object should be initialized
	int cnt = 0;
	const int sz = cnt;
	++cnt;
	++sz; //const object can't be change
}