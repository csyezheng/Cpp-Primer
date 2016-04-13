#ifndef STRVEC_H
#define STRVEC_H

#include <utility>
#include <allocators>
#include <string>
#include <initializer_list>

class StrVec
{
public:
	StrVec();
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec &operator= (const StrVec&);
	~StrVec();
	StrVec(StrVec&&) noexcept;
	StrVec &operator= (StrVec&&) noexcept;
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void push_back(const std::string &);
	void pop_back();
	std::string *begin() const;
	std::string *end() const;
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