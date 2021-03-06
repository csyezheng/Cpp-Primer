#ifndef STR_H
#define STR_H

#include <memory>
#include <utility>
#include <iostream>

class String
{
	friend std::istream &operator>> (std::istream&, String&);
	friend std::ostream &operator<< (std::ostream&, const String&);
	friend bool operator== (const String&, const String&);
	friend bool operator< (const String&, const String&);
public:
	String();
	String(const char*);
	String(const String&);
	String &operator=(const String&);
	~String();
	String(String&&) noexcept;
	String &operator=(String&&) noexcept;
	size_t size() const;
	bool empty() const;
	size_t capacity() const;
	char *begin() const;
	char *end() const;
	void push_back(const char&);
	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, char);
	char &operator[](std::size_t);
	const char &operator[] (std::size_t) const;
private:
	std::allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
	void chk_n_alloc();
	void reallocate();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void alloc_n_move(size_t);
	void free();
};


std::istream &operator>> (std::istream&, String&);
std::ostream &operator<< (std::ostream&, const String&);
bool operator== (const String&, const String&);
bool operator!= (const String&, const String&);
bool operator< (const String&, const String&);
bool operator> (const String&, const String&);
bool operator<= (const String&, const String&);
bool operator>= (const String&, const String&);

#endif