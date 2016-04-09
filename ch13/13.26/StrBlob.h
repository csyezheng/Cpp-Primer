#ifndef STRBLOB_H
#define STRBLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	StrBlob(const StrBlob&);
	StrBlob &operator= (const StrBlob&);
	size_type size() const;
	bool empty() const;
	void push_back(const std::string&);
	void pop_back();
	std::string &front();
	const std::string front() const;
	std::string &back();
	const std::string back() const;
	StrBlobPtr &begin();
	StrBlobPtr &end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob&, std::size_t sz = 0);
	std::string &deref() const;
	StrBlobPtr &incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(const std::size_t i, const std::string&) const;
};

#endif