#ifndef STRING_H
#define STRING_H

#include <memory>

class String
{
	String();
	String(const char*);
	size_t size() const;

private:
	std::allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
	void chk_n_alloc();
	void reallocate();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
};


#endif