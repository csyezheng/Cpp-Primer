#ifndef STRING_H
#define STRING_H

class String
{
public:
	String();
	String(const char *);
	String(const String&);
	String &operator= (const String&);
	~String();
	String(String&&);
	String &operator= (const String&&);
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	char *begin() const;
	char *end() const;
private:
	std::allocator<char> alloc;
	std::char *elements;
	std::char *first_free;
	std::char *cap;
	void ch_n_alloc();
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void reallocate();
	void free();
};

#endif