#include <iostream>

class numbered
{
	friend void f(const numbered&);
public:
	numbered()
	{
		mysn = unique++;
	}
	numbered(const numbered &num)
	{
		mysn = unique++;
	}
private:
	int mysn = 0;
	static int unique;
};

int numbered::unique = 0;

void f(const numbered &s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}