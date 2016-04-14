#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <memory>
#include <stdexcept>
#include "String.h"


String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

String::String(const char *c)
{
	char *ch = const_cast<char*>(c);
	while (ch)
		++ch;
	auto data = alloc_n_copy(c, ch);
	elements = data.first;
	first_free = cap = data.second;
}

String::String(const String &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	elements = data.first;
	first_free = data.second;
}

String &String::operator= (const String &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String::String(String &&rhs) noexcept:
elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

String &String::operator= (String &&rhs) noexcept
{
	if (this != &rhs)
	{
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
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

const char *String::begin() const
{
	return elements;
}

const char *String::end() const
{
	return first_free;
}

void String::push_back(const char &ch)
{
	chk_n_alloc();
	alloc.construct(first_free, ch);
}

void String::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
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

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto newdata = alloc.allocate(e - b);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, *p);
	return{ newdata, dest };
}

void String::free()
{
	for (auto p = first_free; p != elements; )
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

std::istream &operator>> (std::istream &is, String &str)
{
	char ch;
	while (is >> ch)
		str.push_back(ch);
	if (!is)
		str = String();
	return is;
}

std::ostream &operator<< (std::ostream &os, const String &str)
{
	std::ostream_iterator<char> outer(os);
	std::copy(str.begin(), str.end(), outer);
	return os;
}
