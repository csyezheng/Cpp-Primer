#ifndef STRBLOB_H
#define STRBLOB_H


#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlobPtr;
class ConstStrBlobPtr;

/*================================= for StrBlob ===========================================*/

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator== (const StrBlob&, const StrBlob&);
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string>);

	StrBlob(const StrBlob&);
	StrBlob &operator= (const StrBlob&);
	StrBlob(StrBlob&&) noexcept;
	StrBlob &operator= (StrBlob&&) noexcept;

	size_type size() const;
	bool empty() const;

	std::string &front();
	const std::string front() const;
	std::string &back();
	const std::string back() const;

	void push_back(const std::string&);
	void push_back(std::string &&);
	void pop_back();

	StrBlobPtr begin();
	ConstStrBlobPtr cbegin() const;
	StrBlobPtr end();
	ConstStrBlobPtr cend() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
};



/*=================================== StrBlobPtr =========================================*/

class StrBlobPtr
{
	friend bool operator== (const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr(StrBlob&, size_t sz = 0);
	std::string &deref() const;
	StrBlobPtr &incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(const size_t, const std::string&) const;
};

/*================================= ConstStrBlobPtr =================================*/

class ConstStrBlobPtr
{
	friend bool operator== (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
public:
	ConstStrBlobPtr(const StrBlob&, size_t sz = 0);
	const std::string deref() const;
	ConstStrBlobPtr &incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(const size_t i, const std::string&) const;
};


bool operator== (const StrBlob&, const StrBlob&);
bool operator!= (const StrBlob&, const StrBlob&);
bool operator== (const StrBlobPtr&, const StrBlobPtr&);
bool operator!= (const StrBlobPtr&, const StrBlobPtr&);
bool operator== (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!= (const ConstStrBlobPtr&, const ConstStrBlobPtr&);

#endif