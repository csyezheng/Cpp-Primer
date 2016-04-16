#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <allocators>
#include <utility>
#include <initializer_list>

class StrVec
{
	friend bool operator== (const StrVec&, const StrVec&);
	friend bool operator< (const StrVec&, const StrVec&);
	friend bool operator> (const StrVec&, const StrVec&);
public:
	StrVec();
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec &operator= (const StrVec&);
	~StrVec();
	StrVec(StrVec&&) noexcept;
	StrVec &operator= (StrVec&&) noexcept;
	StrVec &operator= (std::initializer_list<std::string> il);
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void push_back(const std::string&);
	void push_back(std::string&&);
	void pop_back();
	std::string *begin() const;
	std::string *end() const;
	void reserve(size_t newcap);
	void resize(size_t newsz);
	void resize(size_t newsz, const std::string&);
	std::string &operator[](std::size_t);
	const std::string &operator[](std::size_t) const;
private:
	std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	void chk_n_alloc();
	void reallocate();
	std::pair<std::string*, std::string*>
		alloc_n_copy(const std::string*, const std::string*);
	std::pair<std::string*, std::string*>
		alloc_n_move(const std::string*, const std::string*);
	void free();
};

bool operator== (const StrVec&, const StrVec&);
bool operator!= (const StrVec&, const StrVec&);
bool operator< (const StrVec&, const StrVec&);
bool operator> (const StrVec&, const StrVec&);
bool operator<= (const StrVec&, const StrVec&);
bool operator>= (const StrVec&, const StrVec&);

#endif