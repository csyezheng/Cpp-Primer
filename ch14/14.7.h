#ifndef STRING_H
#define STRING_H

#include <memory>
#include <iostream>

class String
{
	friend std::ostream &operator<< (std::ostream&, const String &);
public:
	String();
	String(const char*);
	String(const String &);
	String &operator= (const String &);
	String(String &&) noexcept;
	String &operator= (String &&) noexcept;
	~String();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void push_back(const char *);
	const char *begin() const;
	const char *end() const;
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

std::ostream &operator<< (std::ostream &os, const String &);


#endif