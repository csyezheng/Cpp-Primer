#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
	Employee(const std::string &s = std::string()) :
		name(s), id(unique++) { }
	// employee can't copy in real world
private:
	std::string name;
	std::size_t id;
	static std::size_t unique;
};

std::size_t Employee::unique = 0;

#endif