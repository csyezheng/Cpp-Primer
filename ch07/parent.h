#include <iostream>

using namespace std;

struct Person
{
	std::string getName() const
	{
		return name;
	}
	std::string getAddr() const
	{
		return address;
	}
	std::string name;
	std::string address;
}

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);