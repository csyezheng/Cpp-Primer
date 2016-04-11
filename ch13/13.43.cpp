#include <string>
#include <initializer_list>
#include <allocators>
#include <stdexcept>
#include <utility>
#include <algorigthm>
#include "13.43.h"

using std::string;
using std::initializer_list;
using std::allocator;
using std::runtime_error;
using std::pair;

StrVec::StrVec() :elements(nullptr), first_free(nullptr), cap(first_free) { }

StrVec::StrVec(initializer_list<string> il)
{
	auto data = alloc.allocate(il.size());
	auto dest = data;
	for (auto iter = il.begin(); iter != il.end(); ++iter)
		alloc.construct(dest++, *iter++);
}

StrVec::StrVec(const StrVec &sv)
{
	auto data = alloc_n_copy(sv.begin(), sv.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec &StrVec::operator= (const StrVec &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

size_t StrVec::size() const
{
	return first_free - elements;
}

bool StrVec::empty() const
{
	return size() ? true : false;
}

size_t StrVec::capacity() const
{
	return cap - elements;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::pop_back()
{
	if (first_free != elements)
		alloc.destroy(first_free--);
}

string &StrVec::front()
{
	if (!elements)
		throw runtime_error("front on empty StrVec");
	return *elements;
}

const string StrVec::front() const
{
	if (!elements)
		throw runtime_error("front on empty StrVec");
	return *elements;
}

string &StrVec::back()
{
	if (!elements)
		throw runtime_error("back on empty StrVec");
	return *(first_free - 1);
}

const string StrVec::back() const
{
	if (!elements)
		throw runtime_error("back on empry StrVec");
	return *(first_free - 1);
}

string *StrVec::begin() const
{
	return elements;
}

string *StrVec::end() const
{
	return first_free;
}

void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto newdata = alloc.allocate(e - b);
	auto dest = newdata;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, *p);
	return{ newdata, dest };
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
	cap = newdata + newcapacity;
}

void StrVec::free()
{
	for (auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);

	alloc.deallocate(elements, cap - elements);
	elements = first_free = cap = nullptr;
}

int main()
{

}