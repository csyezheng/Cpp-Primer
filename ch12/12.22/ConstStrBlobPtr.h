#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>


class ConstStrBlobPtr;

class StrBlob
{
public:
	using size_type = std::vector<std::string>::size_type;
	friend class ConstStrBlobPtr;
	StrBlob::StrBlob();
	StrBlob::StrBlob(std::initializer_list<std::string> il);
	size_type size() const;
	bool empty() const;
	void push_back(const std::string &str);
	void pop_back();
	std::string &front();
	const std::string front() const;
	std::string &back();
	const std::string back() const;
	const ConstStrBlobPtr cbegin() const;
	const ConstStrBlobPtr cend() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
};

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr();
	ConstStrBlobPtr(const StrBlob &sb, std::size_t sz = 0);
	const std::string &deref() const;
	ConstStrBlobPtr &incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(const std::size_t i, const std::string &msg) const;
};


#endif