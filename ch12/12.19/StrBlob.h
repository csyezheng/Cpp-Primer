#ifndef STRBLOB_H
#define STRBLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>

class StrBlobPtr;

class StrBlob
{
public:
	friend StrBlobPtr;
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const;
	bool empty() const;
	void push_back(const std::string &str);
	void pop_back();
	std::string &front();
	const std::string front() const;
	std::string &back();
	const std::string back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
};


class StrBlobPtr
{
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob &a, size_t = 0);
	std::string &deref() const;
	StrBlobPtr &incr();
	bool operator!=(const StrBlobPtr&) const;
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(const size_t i, const std::string &msg) const;
};


#endif