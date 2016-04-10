#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <allocators>
#include <initializer_list>
#include <utility>

class StrVec
{
public:
	StrVec();
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec&);
	StrVec &operator= (const StrVec&);
	std::string *begin() const;
	std::string *end() const;
	void push_back(const std::string&);
	size_t size() const;
	size_t capacity() const;
private:
	std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	void chk_n_alloc();
	void reallocate();
	std::pair<std::string*, std::string*>
		alloc_n_copy(const std::string*, const std::string*);
	void free();
};


#endif