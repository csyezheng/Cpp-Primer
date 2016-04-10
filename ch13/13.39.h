#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <allocators>
#include <utility>

class StrVec
{
public:
	StrVec();
	StrVec(const StrVec&);
	StrVec &operator= (const StrVec&);
	~StrVec();
	std::string *begin() const;
	std::string *end() const;
	std::size_t size() const;
	bool empty() const;
	void push_back(const std::string&);
	void pop_back();	
private:
	std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	void chk_n_alloc();
	void reallocate();
	std::pair<std::string*, std::string*>
		alloc_n_copy(const std::string *b, const std::string *e);
	void free();
};



#endif