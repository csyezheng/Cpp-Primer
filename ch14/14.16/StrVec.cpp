#include <string>
#include <allocators>
#include <utility>
#include <initializer_list>
#include <algorithm>
#include "StrVec.h"

using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec::StrVec(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	elements = data.first;
	first_free = data.second;
}

StrVec &StrVec::operator= (const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

StrVec::StrVec(StrVec &&rhs) noexcept:
	elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec &StrVec::operator= (StrVec &&rhs) noexcept
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

StrVec &StrVec::operator= (std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

size_t StrVec::size() const
{
	return first_free - elements;
}

size_t StrVec::capacity() const
{
	return cap - elements;
}

bool StrVec::empty() const
{
	return size() ? false : true;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free, std::move(s));
}

void StrVec::pop_back()
{
	alloc.destroy(--first_free);
}

string *StrVec::begin() const
{
	return elements;
}

string *StrVec::end() const
{
	return first_free;
}

void StrVec::reserve(size_t newcap)
{
	if (capacity() < newcap)
	{
		alloc.allocate(newcap);
		auto data = alloc_n_move(elements, first_free);
		elements = data.first;
		first_free = cap = data.second;
	}
}

void StrVec::resize(size_t newsz)
{
	if (size() <= newsz)
	{
		for (auto sz = size(); sz != newsz; ++sz)
			alloc.construct(first_free++, std::string());
	}
	else
	{
		for (auto sz = size(); sz != newsz; --sz)
			alloc.destroy(--first_free);
	}
}

void StrVec::resize(size_t newsz, const string &msg)
{
	if (size() <= newsz)
	{
		for (auto sz = size(); sz != newsz; ++sz)
			alloc.construct(first_free++, string());
	}
	else
	{
		for (auto sz = size(); sz != newsz; --sz)
			alloc.destroy(--first_free);
	}
}

string &StrVec::operator[](std::size_t n)
{
	if (size() <= n)
		throw std::runtime_error("operator[] past end of StrVec");
	return elements[n];
}

const string &StrVec::operator[](std::size_t n) const
{
	if (size() <= n)
		throw std::runtime_error("operator[] past end of StrVec");
	return elements[n];
}

void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, *p);
	alloc.deallocate(elements, cap - elements);
}

pair<string*, string*> StrVec::alloc_n_move(const string *b, const string *e)
{
	auto newdata = alloc.allocate(b - e);
	auto dest = newdata;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, std::move(*p));
	return{ newdata, dest };
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	auto dest = data;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, *p);
	return{ data, dest };
}

void StrVec::free()
{
	for (auto p = first_free; p != elements; )
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

bool operator== (const StrVec &lhs, const StrVec &rhs)
{
	if (lhs.size() == rhs.size())
	{
		for (auto p = lhs.begin(), q = rhs.begin(); p != lhs.end(); ++p, ++q)
			if (*p != *q)
				return false;
		return true;
	}
	else
		return false;
}

bool operator!= (const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const StrVec &lhs, const StrVec &rhs)
{
	//////////////////////////////////////////////////////////////////////////////////////
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	//////////////////////////////////////////////////////////////////////////////////////
	return false;
}

bool operator> (const StrVec &lhs, const StrVec &rhs)
{
	return rhs < lhs;
}

bool operator<= (const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs > rhs);
}

bool operator>= (const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs < rhs);
}

