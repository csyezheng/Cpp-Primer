int main()
{
	int i = 0, &r = i;
	auto a = r;   // the attribut of "const" is ignored
	const int ci = i, &cr = ci;
	auto b = ci;  //ignore the "const"
	auto c = cr;  //ignore the "const"
	auto d = &i;  // d is a pointer
	auto e = &ci;  //e is a pointer point to a const value
	auto &g = ci; // the attribute of "const" is releaved
	a = 42;
	b = 42;
	c = 42;
	d = 42; //a pointer can't be assigned with int
	e = 42; //the same above
	g = 42;
}