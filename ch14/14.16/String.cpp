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

char *String::begin() const
{
	return elements;
}

char *String::end() const
{
	return first_free;
}

void String::push_back(const char &ch)
{
	chk_n_alloc();
	alloc.construct(first_free, ch);
}

void String::reserve(size_t newcap)
{
	if (size() < newcap)
	{
		alloc_n_move(newcap);
	}
}

void String::resize(size_t newsz)
{
	resize(newsz, ' ');
}

void String::resize(size_t newsz, const char c)
{
	if (size() <= newsz)
	{
		for (auto i = size(); i != newsz; ++i)
			push_back(c);
	}
	else
	{
		for (auto i = newsz; i != size(); --i)
			alloc.destroy(--first_free);
	}
}

char &String::operator[](std::size_t n)
{
	if (size() <= n)
		throw std::runtime_error("operator[] past end of String");
	return elements[n];
}

const char &String::operator[](std::size_t n) const
{
	if (size() <= n)
		throw std::runtime_error("operator[] past end of String");
	return elements[n];
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

void String::alloc_n_move(size_t sz)
{
	auto newdata = alloc.allocate(sz);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, std::move(*p));
	elements = newdata;
	first_free = dest;
	cap = elements + sz;
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

bool operator== (const String &lhs, const String &rhs)
{
	if (lhs.size() == rhs.size())
	{
		for (auto p = lhs.elements, q = rhs.elements; p != lhs.first_free; ++p, ++q)
		{
			if (*p != *q)
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!= (const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const String &lhs, const String &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator> (const String &lhs, const String &rhs)
{
	return rhs < lhs;
}

bool operator<= (const String &lhs, const String &rhs)
{
	return !(lhs > rhs);
}

bool operator>= (const String &lhs, const String &rhs)
{
	return !(lhs < rhs);
}