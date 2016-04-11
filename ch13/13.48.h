#ifndef STRING_H
#define STRING_H

#include <allocators>
#include <memory>

class String
{
public:
	String();
	String(const char *);
	String(const String&);
	String &operator= (const String&);
	~String();
	char *begin() const;
	char *end() const;
	size_t size() const;
	bool empty() const;
	size_t capacity() const;
private:
	std::allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
	void chk_n_alloc();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void reallocate();
	void free();
};

#endif