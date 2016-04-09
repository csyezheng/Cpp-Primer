#ifndef STRBLOB_H
#define STRBLOB_H

#include <string>
#include <vector>
#include <memory>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
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
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob &sb, std::size_t sz);
	std::string &deref() const;
	StrBlobPtr &incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	std::shared_ptr<std::vector<std::string>> check(const std::size_t i,
		const std::string &msg) const;
};


class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr();
	ConstStrBlobPtr(const StrBlob &sb, const std::size_t);
	const std::string deref() const;
	ConstStrBlobPtr &incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(const std::size_t i, const std::string &msg) const;
};

#endif 