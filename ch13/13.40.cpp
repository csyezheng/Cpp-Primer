#include <string>
#include <allocators>
#include <utility>
#include <initializer_list>
#include <memory>
#include "13.40.h"

using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

StrVec::StrVec(initializer_list<string> il)
{
	auto data = alloc.allocate(il.size());
	auto dest = data;
	for (auto iter = il.begin(); iter != il.end(); ++iter)
		alloc.construct(dest++, *iter);
	elements = data;
	first_free = cap = dest;
}

StrVec::StrVec(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec &StrVec::operator= (const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

string *StrVec::begin() const
{
	return elements;
}

string *StrVec::end() const
{
	return first_free;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

size_t StrVec::size() const
{
	return first_free - elements;
}

size_t StrVec::capacity() const
{
	return cap - elements;
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
	auto p = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(newdata++, *p++);
	elements = newdata;
	first_free = cap = p;
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto newdata = alloc.allocate(b - e);
	auto dest = newdata;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, *p);
	return{ newdata, dest };
}

void StrVec::free()
{
	for (auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

int main()
{
	return 0;
}