#include <iostream>
#include "Person.h"

std::istream &read(std::istream &is, Person &people)
{
	is >> people.name >> people.address;
	return is;
}

std::ostream &print(std::ostream &os, Person &people)
{
	os << people.getName() << people.getAddr();
	return os;
}