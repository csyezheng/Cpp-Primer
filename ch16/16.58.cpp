#include <string>
#include <initializer_list>
#include <utility>
#include <stdexcept>
#include "16.58.h"

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec::StrVec(std::initializer_list<std::string> &&il)
{
	auto data = alloc_n_move(il.begin(), il.end());
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
	elements = data.first;
	first_free = data.second;
	return *this;
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

StrVec::~StrVec()
{
	free();
}

std::size_t StrVec::size() const
{
	return first_free - elements;
}

std::size_t StrVec::capacity() const
{
	return cap - elements;
}

bool StrVec::empty() const
{
	return size() ? false : true;
}

void StrVec::push_back(const std::string &item)
{
	chk_n_alloc();
	alloc.construct(first_free++, item);
}

void StrVec::push_back(std::string &&item)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(item));
}

void StrVec::pop_back()
{
	if (elements)
		alloc.destroy(--first_free);
}

std::string *StrVec::begin() const
{
	return elements;
}

std::string *StrVec::end() const
{
	return first_free;
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
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto newdata = alloc.allocate(e - b);
	auto dest = newdata;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, *p);
	return{ newdata, dest };
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_move(const std::string *b, const std::string *e)
{
	auto newdata = alloc.allocate(e - b);
	auto dest = newdata;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, std::move(*p));
	return{ newdata, dest };
}

void StrVec::free()
{
	for (auto p = first_free; p != elements; )
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

int main()
{

}