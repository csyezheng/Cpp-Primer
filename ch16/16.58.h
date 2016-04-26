#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <allocators>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
	StrVec();
	StrVec(std::initializer_list<std::string>);
	StrVec(std::initializer_list<std::string>&&);
	StrVec(const StrVec&);
	StrVec &operator= (const StrVec&);
	StrVec(StrVec &&) noexcept;
	StrVec &operator= (StrVec &&) noexcept;
	~StrVec();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void push_back(const std::string &);
	void push_back(std::string &&);
	void pop_back();
	template<typename...Args> void emplace_back(Args&&... args);
	std::string *begin() const;
	std::string *end() const;
private:
	std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	void chk_n_alloc();
	std::pair<std::string *, std::string*>
		alloc_n_copy(const std::string*, const std::string*);
	std::pair<std::string*, std::string*>
		alloc_n_move(const std::string*, const std::string*);
	void reallocate();
	void free();
};


template<typename...Args>
void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(std::move(args))...);
}


#endif