#ifndef STRING
#define STRING

#include <allocators>
#include <memory>
#include <utility>

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	String &operator= (const String &rhs);
	~String();
	char *begin() const;
	char *end() const;
private:
	std::allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
	std::pair<char*, char*>
		alloc_n_copy(const char*, const char*);
	void free();
};


#endif