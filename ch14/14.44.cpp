#include <iostream>
#include <functional>
#include <map>
#include <string>


int main()
{
	std::map<std::string, std::function<int(const int, const int)>> calculus;
	calculus.insert({ "+", std::plus<int>() });
	calculus.insert({ "-", std::minus<int>() });
	calculus.insert({ "*", std::multiplies<int>() });
	calculus.insert({ "/", std::divides<int>() });
	calculus.insert({ "%", std::modulus<int>() });

	std::cout << "Please enter a number a operation and a second number in order" << std::endl;
	int v1, v2;
	std::string op;
	std::cin >> v1 >> op >> v2;
	std::cout << "the rusult is " << calculus[op](v1, v2) << std::endl;
	return 0;
}