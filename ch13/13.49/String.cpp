#include <utility>
#include <iostream>
#include "String.h"

String::String() :
	elements(nullptr), first_free(nullptr), cap(nullptr) { }

String::String(const char *c)
{
	char *ch = const_cast<char*>(c);
	while (ch)
		++ch;
	auto data = alloc_n_copy(c, ch);
	elements = data.first;
	first_free = cap = data.second;
}

String::String(const String &str)
{
	auto data = alloc_n_copy(str.begin(), str.end());
	elements = data.first;
	first_free = cap = data.second;
	std::cout << "String(const String&)" << std::endl;
}

String &String::operator= (const String &str)
{
	auto data = alloc_n_copy(str.begin(), str.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	std::cout << "String &operator= (const String&)" << std::endl;
	return *this;
}

String::~String()
{
	free();
}

String::String(String &&rhs) noexcept: 
elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
	std::cout << "String(String&&)" << std::endl;
}

String &String::operator= (String &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
		std::cout << "String &operator= (const String&)" << std::endl;
	}
	return *this;
}

size_t String::size() const
{
	return first_free - elements;
}

size_t String::capacity() const
{
	return cap - elements;
}

bool String::empty() const
{
	return size() ? false : true;
}

char *String::begin() const
{
	return elements;
}

char *String::end() const
{
	return first_free;
}

void String::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto newdata = alloc.allocate(e - b);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, *p);
	return{ newdata, dest };
}

void String::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, *p);
	elements = newdata;
	first_free = cap = dest;
}

void String::free()
{
	for (auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
	elements = first_free = cap = nullptr;
}
