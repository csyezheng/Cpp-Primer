#include <string>
#include <allocators>
#include <utility>
#include <stdexcept>
#include <memory>
#include "13.39.h"

using std::string;
using std::allocator;
using std::pair;

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

StrVec::StrVec(const StrVec &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());        //////////////////
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec &StrVec::operator= (const StrVec &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), end());           ////////////////////
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

string *StrVec::begin() const
{
	return elements;
}

string *StrVec::end() const
{
	return first_free;
}

std::size_t StrVec::size() const
{
	return first_free - elements;
}

bool StrVec::empty() const
{
	return size() ? true : false;
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::pop_back()
{
	if (size())
		alloc.destroy(first_free--);
	else
		throw std::out_of_range("pop_back on empty StrVec");
}

void StrVec::chk_n_alloc()
{
	if (first_free == cap)
		reallocate();
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, *elem++);
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e) 
{
	auto data = alloc.allocate(b - e);
	return{ data, std::uninitialized_copy(b, e, data) };         /////////////////
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; )
			alloc.destroy(--first_free);
		alloc.deallocate(elements, cap - elements);
	}
}

int main()
{

}