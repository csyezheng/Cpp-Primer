int main()
{
	const int i = 42;
	auto j = i;  //j is a type of "int"
	const auto &k = i;  // k is a type of "int"
	auto *p = &i;  // p is a pointer of int
	const auto j2 = i, &k2 = i;  // j2 is "const int" , k2 is "const referenece of int"
}