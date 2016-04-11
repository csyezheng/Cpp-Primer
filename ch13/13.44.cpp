#include <allocators>
#include <utility>
#include "13.44.h"

using std::pair;

String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) { }

String::String(const char *c)
{
	char *ch = const_cast<char*>(c);
	while (*ch)
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
}

String &String::operator = (const String &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String::~String()
{
	free();
}

char *String::begin() const
{
	return elements;
}

char *String::end() const
{
	return first_free;
}



pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto newdata = alloc.allocate(b - e);
	auto dest = newdata;
	for (auto p = b; p != e; ++p)
		alloc.construct(dest++, *p);
	return{ newdata, dest };
}

void String::free()
{
	for (auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
	elements = first_free = cap = nullptr;
}

int main()
{

}