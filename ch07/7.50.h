#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>



class Person
{
public:
	friend std::istream &read(std::istream &is, Person &people);
	friend std::ostream &print(std::ostream &os, const Person &people);
	// constructor functions
	Person() = default;
	Person(const std::string &s, const std::string &a) :
		name(s), address(a) { }
	explicit Person(std::istream &is) { read(is, *this); }

	// member functions
	std::string getName() const
	{
		return name;
	}
	std::string getAddr() const
	{
		return address;
	}
private:
	// member various
	std::string name;
	std::string address;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);






//=======================================
// the following code should be define in other file
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
#endif
