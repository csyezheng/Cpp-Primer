#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <allocators>
#include <initializer_list>

class StrVec
{
	StrVec();
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec &operator= (const StrVec&);
	~StrVec();
	size_t size() const;
	bool empty() const;
	size_t capacity() const;
	void push_back(const std::string&);
	void pop_back();
	std::string &back();
	const std::string back() const;
	std::string &front();
	const std::string front() const;
	std::string *begin() const;
	std::string *end() const;
private:
	std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	void chk_n_alloc();
	std::pair<std::string*, std::string*>
		alloc_n_copy(const std::string*, const std::string*);
	void reallocate();
	void free();
};


#endif